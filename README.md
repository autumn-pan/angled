# Angled

This is a CPP math library adding matrices, quaternions, and euler angles. This was designed specifically to support rotations. It is used for modelling rotations and orientations, specifically aimed at running physics calculations and real time filtering. I made this out of necessity for a way to model object in 3-Space as my other projects became more advanced. Angled was proposed as a solution to this, serving as a way to model rotating objects in 3D.

## Installation
```git clone https://github.com/autumn-pan/angled```
Run the above command to clone this repository. Then, include any necessary headers from the `/include` directory. This project is meant to be minimalistic and as such, retained a minimalistic build system.

## How I Made This
I have self-studying linear algebra before this project and was confident with matrices already. However, this project still tested my ability to apply them, and introduced challenging new concepts like hypercomplex numbers. I had to rigorously study these, as well as algorithms and group theory involved for handling rotations. Abstract algebra is a challenging topic, and although I only studied it briefly for this, I still found it new and challenging. In summary, the mathematical theory was very heavy behind this project. This was also the time when I began to unit test more, and I used this project as an opportunity to test every single subsystem, and the level of rigor was something new. I spent a few weeks on and off with this project, but it ultimately took about twenty hours including theory.
