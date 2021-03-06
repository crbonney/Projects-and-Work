## Default modules imported. Import more if you need to.

import numpy as np
from scipy.signal import convolve2d as conv2
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
# Implement using conjugate gradient, with a weight = 0 for mask == 0, and proportional
# to n_z^2 elsewhere. See slides.

def ntod(nrm, mask, lmda):

    dims = mask.shape
    size = mask.size

    # initialize kernels and their flipped versions
    fx = np.array([0.5, 0, -0.5]).reshape([1,3])
    fy = np.array([-0.5, 0, 0.5]).reshape([3,1])
    fx_bar = fx[::-1,::-1]
    fy_bar = fy[::-1,::-1]

    # fr = fr_bar since its symmetric about both axes
    fr = np.ones([3,3])*-1/9
    fr[1,1] = fr[1,1]+1

    # get indices of pixels not masked
    mask = mask.reshape(-1)
    valid = np.where(mask > 0)[0]


    # calculate gx,gy,w from the surface norm of valid pixels (set the rest to 0)
    gx = np.zeros([size,1])
    gy = np.zeros([size,1])
    w = np.zeros([size,1])

    nrm = nrm.reshape([-1,3])
    nx = nrm[valid,0:1]
    ny = nrm[valid,1:2]
    nz = nrm[valid,2:3]

    gx[valid] = -nx/(nz)
    gy[valid] = -ny/(nz)
    w[valid] = nz**2

    gx = gx.reshape(dims)
    gy = gy.reshape(dims)
    w = w.reshape(dims)


    ## initialization of conjugate gradient method

    # inverse FFT of Fx_bar*Gx + Fy_bar*Gy
    b =     conv2(gx*w,fx_bar,mode='same')
    b = b + conv2(gy*w,fy_bar,mode='same')

    Z = np.zeros(dims)

    # r0 = b - Q*Z,   but Z = 0, so Q*Z = 0 and r0 = b
    r = b
    p = r


    ## iterative update for conjugate gradient described in lecture   
    # we don't have to keep track of terms from previous iterations, so we just update over them
    for i in range(100):
        
        Qpk = Qp(p,w,lmda)
        r_sq = np.sum(r*r)
        
        alpha = r_sq/np.sum(p*Qpk)
        
        Z = Z + alpha*p
        
        r = r - alpha*Qpk
        
        beta = np.sum(r*r)/r_sq
        
        p = r + beta*p
        
    # returns final value of Z (Z_K)
    return Z
    
# function to compute Q matrix multiplied by image shaped p
def Qp(p,w,lmda):
    
    # initialize kernels
    fr = np.ones([3,3])*-1/9
    fr[1,1] = fr[1,1]+1

    fx = np.array([0.5, 0, -0.5]).reshape([1,3])
    fy = np.array([-0.5, 0, 0.5]).reshape([3,1])
    fx_bar = fx[::-1,::-1]
    fy_bar = fy[::-1,::-1]

    # compute each part of Q individually and add them togehter at the end    
    Qp1 = conv2(p,fx,mode='same')
    Qp1 = conv2(Qp1*w,fx_bar,mode='same')

    Qp2 = conv2(p,fy,mode='same')
    Qp2 = conv2(Qp2*w,fy_bar,mode='same')
    
    Qp3 = conv2(p,fr,mode='same')
    Qp3 = conv2(Qp3,fr,mode='same')

    return Qp1 + Qp2 + Qp3*lmda

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
Z = ntod(nrm,mask,1e-7)


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
                linewidth=0,cmap=cm.inferno,shade=False,\
                vmin=-lim,vmax=lim)

ax.set_xlim3d(-450,450)
ax.set_ylim3d(-450,450)
ax.set_zlim3d(-450,450)

plt.show()
