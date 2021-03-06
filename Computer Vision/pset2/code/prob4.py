## Default modules imported. Import more if you need to.

import numpy as np
from skimage.io import imread, imsave


## Fill out these functions yourself


# Inputs:
#    nrm: HxWx3. Unit normal vectors at each location. All zeros at mask == 0
#    mask: A 0-1 mask of size HxW, showing where observed data is 'valid'.
#    lmda: Scalar value of lambda to be used for regularizer weight as in slides.
#
# Returns depth map Z of size HxW.
#
# Be careful about division by 0.
#
# Implement in Fourier Domain / Frankot-Chellappa
def ntod(nrm, mask, lmda):

    dims = mask.shape
    size = mask.size
    
    # build the kernels for the algorithm, kernpad them, and take their FFTs and conjugates
    fr = np.ones([3,3])*-1/9
    fr[1,1] = fr[1,1]+1
    
    fx = np.array([0.5, 0, -0.5]).reshape([1,3])
    fy = np.array([-0.5, 0, 0.5]).reshape([3,1])

    fx = kernpad(fx, dims)
    fy = kernpad(fy, dims)
    fr = kernpad(fr, dims)
    
    Fx = np.fft.fft2(fx)
    Fy = np.fft.fft2(fy)
    Fr = np.fft.fft2(fr)

    Fx_bar = np.conjugate(Fx)
    Fy_bar = np.conjugate(Fy)
    Fr_bar = np.conjugate(Fr)


    # pixels that aren't masked
    mask = mask.reshape(-1)
    valid = np.where(mask > 0)[0]
 
 
    # calculate gx,gy from the surface norm of valid pixels (set the rest to 0)
    gx = np.zeros([size,1])
    gy = np.zeros([size,1])

    nrm = nrm.reshape([-1,3])
    nx = nrm[valid,0:1]
    ny = nrm[valid,1:2]
    nz = nrm[valid,2:3]

    gx[valid] = -nx/(nz)
    gy[valid] = -ny/(nz)

    #reshape gx,gy back into image shape for FFT
    gx = gx.reshape(dims)
    gy = gy.reshape(dims)
    
    Gx = np.fft.fft2(gx)
    Gy = np.fft.fft2(gy)

    
    #solution to least squares in Fourier Space from F-C method
    FZ = (Fx_bar*Gx + Fy_bar*Gy)/(Fx_bar*Fx + Fy_bar*Fy + lmda*Fr_bar*Fr + 10**(-12))  
    
    #set bias to 0
    FZ[0,0] = 0

    #take inverse FFT to get Z
    Z = np.fft.ifft2(FZ)
    
    #grab the real part to get rid of any imaginary bits from floating point errors
    Z = np.real(Z)
    return Z


# Kernpad from Pset1, problem 4
def kernpad(K,size):
    Ko = np.zeros(size,dtype=np.float32)
    Ko[:K.shape[0],:K.shape[1]] = K
    Ko = np.roll(Ko, int(-(K.shape[0]-1)/2),axis=0)    
    Ko = np.roll(Ko, int(-(K.shape[1]-1)/2),axis=1)    
    return Ko


########################## Support code below

from os.path import normpath as fn # Fixes window/linux path conventions
import warnings
warnings.filterwarnings('ignore')

import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D


#### Main function

nrm = imread(fn('inputs/phstereo/true_normals.png'))

# Un-comment  next line to read your output instead
# nrm = imread(fn('outputs/prob3_nrm.png'))


mask = np.float32(imread(fn('inputs/phstereo/mask.png')) > 0)

nrm = np.float32(nrm/255.0)
nrm = nrm*2.0-1.0
nrm = nrm * mask[:,:,np.newaxis]


# Main Call
Z = ntod(nrm,mask,1e-6)


# Plot 3D shape

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

x,y = np.meshgrid(np.float32(range(nrm.shape[1])),np.float32(range(nrm.shape[0])))
x = x - np.mean(x[:])
y = y - np.mean(y[:])

Zmsk = Z.copy()
Zmsk[mask == 0] = np.nan
Zmsk = Zmsk - np.nanmedian(Zmsk[:])

lim = 100
ax.plot_surface(x,-y,Zmsk, \
                linewidth=0,cmap=cm.inferno,shade=True,\
                vmin=-lim,vmax=lim)

ax.set_xlim3d(-450,450)
ax.set_ylim3d(-450,450)
ax.set_zlim3d(-450,450)

plt.show()
