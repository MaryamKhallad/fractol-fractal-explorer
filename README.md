*This project has been created as part of the 42 curriculum by mkhallad.*

# fractol

## Description

**fractol** is a graphical program that renders beautiful fractals in real-time, allowing interactive exploration through zooming and parameter manipulation. The project demonstrates the mathematical beauty of fractals while developing skills in computer graphics, optimization, and event-driven programming.

### Goal
The primary goal of this project is to:

Understand and implement fractal generation algorithms (Mandelbrot and Julia sets)
Master the use of the MiniLibX graphics library
Handle complex numbers and mathematical computations
Optimize rendering performance for smooth real-time interaction
Implement responsive event handling and window management

### Overview
Fractals are infinitely complex patterns that are self-similar across different scales. This program generates and displays two main types of fractals:

Mandelbrot Set: A set of complex numbers for which the iterative function f(z) = z² + c does not diverge
Julia Set: Similar to Mandelbrot but uses a constant complex parameter, creating various artistic patterns

The Julia set :is now associated with those points z = x + iy on the complex plane for which the series zn+1 = zn2 + c does not tend to infinity. c is a complex constant, one gets a different Julia set for each c. The initial value z0 for the series is each point in the image plane. In the broader sense the exact form of the iterated function may be anything, the general form being zn+1 = f(zn)

The Burning Ship fractal : the complex plane which will either escape or remain bounded. The difference between this calculation and that for the Mandelbrot set is that the real and imaginary components are set to their respective absolute values before squaring at each iteration.

---

## Instructions

### Compilation
The project uses a `Makefile` for compilation. To build the executable, run:

```bash
git clone git@vogsphere.42amman.com:vogsphere/intra-uuid-5adb4e73-19df-4806-88ff-fbb3604ff302-7205460-mkhallad fractol
cd fractol
make
```

### Execution
To run the fractol program:

```bash
./fractol Mandelbrot
./fractol Julia <re> <im>
./fractol burning_ship
```

Example with Julia set:
```bash
./fractol Julia -0.7 0.27015
```

## Features

### Mandatory Features
- **Mandelbrot Set**: Interactive rendering of the classic Mandelbrot fractal
- **Julia Set**: Generate Julia sets with configurable complex parameters
- **Burning Ship Fractal**: Alternative fractal visualization
- **Mouse Zoom**: Scroll wheel to zoom in/out around the mouse cursor
- **Real-time Rendering**: Fast, optimized fractal computation
- **Color Mapping**: Psychedelic color gradients based on iteration depth
- **Clean Exit**: ESC key and window close button properly exit the program

### Controls
- **Mouse Wheel Up**: Zoom in (at mouse position)
- **Mouse Wheel Down**: Zoom out (at mouse position)
- **Arrow Keys**: Navigate/pan the fractal view
- **C Key**: Shift colors forward
- **V Key**: Shift colors backward
- **ESC Key**: Exit the program
- **Window Close**: Click the X button to exit

## Resources

- https://en.wikipedia.org/wiki/Mandelbrot_set
- https://en.wikipedia.org/wiki/Julia_set
- https://en.wikipedia.org/wiki/Burning_Ship_fractal
- https://stackoverflow.com/questions/tagged/fractals
- https://www.reddit.com/r/fractals/
- https://fractalfoundation.org/resources/what-are-fractals/

### AI Usage
AI was used to assist with:
- Algorithm understanding (fractal mathematics)
- MiniLibX graphics library usage
- Debugging complex rendering issues
- Color scheme generation
- Zoom implementation
- Code optimization
- Project structure