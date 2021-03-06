## Default modules imported. Import more if you need to.
import numpy as np
from scipy.signal import convolve2d as conv2

# Use these as the x and y derivative filters
fx = np.float32([[1,0,-1]]) * np.float32([[1,1,1]]).T / 6.
fy = fx.T


# Compute optical flow using the lucas kanade method
# Use the fx, fy, defined above as the derivative filters
# and compute derivatives on the average of the two frames.
# Also, consider (x',y') values in a WxW window.
# Return two image shape arrays u,v corresponding to the
# horizontal and vertical flow.
def lucaskanade(f1,f2,W):
    u = np.zeros(f1.shape)
    v = np.zeros(f1.shape)

    summer = np.ones([W,W])

    # add to diagonal elements for stability
    epsilon = 10**-10

    # time gradient
    It = f2-f1
    
    # gradient of avg of two frames
    I = (f2+f1)/2
    Ix = conv2(I, fx, mode='same', boundary='symm')
    Iy = conv2(I, fy, mode='same', boundary='symm')

    # elementwise multiplications of gradient terms
    Ixx = Ix*Ix
    Ixy = Ix*Iy
    Iyy = Iy*Iy
    Ixt = Ix*It
    Iyt = Iy*It

    # local summations using convolution with kernel of ones
    Ixx = conv2(Ixx,summer,mode='same',boundary='fill') + epsilon
    Ixy = conv2(Ixy,summer,mode='same',boundary='fill')
    Iyy = conv2(Iyy,summer,mode='same',boundary='fill') + epsilon
    Ixt = conv2(Ixt,summer,mode='same',boundary='fill')
    Iyt = conv2(Iyt,summer,mode='same',boundary='fill')

    # elementwise solution of 2x2 linear system for every pixel
    u = (Ixy*Iyt-Iyy*Ixt)/(Ixx*Iyy-Ixy*Ixy)
    v = (Ixy*Ixt-Ixx*Iyt)/(Ixx*Iyy-Ixy*Ixy)

    return u,v
    
########################## Support code below

from skimage.io import imread, imsave
from os.path import normpath as fn # Fixes window/linux path conventions
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings('ignore')


f1 = np.float32(imread(fn('inputs/frame10.jpg')))/255.
f2 = np.float32(imread(fn('inputs/frame11.jpg')))/255.

u,v = lucaskanade(f1,f2,11)


# Display quiver plot by downsampling
x = np.arange(u.shape[1])
y = np.arange(u.shape[0])
x,y = np.meshgrid(x,y[::-1])
plt.quiver(x[::8,::8],y[::8,::8],u[::8,::8],-v[::8,::8],pivot='mid')

plt.show()
