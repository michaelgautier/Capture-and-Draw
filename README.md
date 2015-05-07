Capture and Draw
------------------------------------------

When you are writing software sometimes you want to link to new graphics technologies in a loosely coupled way. Today, you may chose DirectX, later, you decide to adopt SDL. Eventually, you may decide that Allegro or SFML is right for your solution. You want the flexibility to present your ideas and functionality in such a way as avoid a large rewrite of the program.

WHAT THIS IS:
------------------------------------------

An attempt to keep the focus on the application rather than the technique of visualization. Some programs are expected to function long-term but would like to tap into new capabilities. The API upon which such programs run has to be stable. That stability, from the point of view of the application layer, is what this solution is all about.

It has tradeoffs. This solution is predominately a passthrough layer to highly capable interactive solutions today and tomorrow. The true nature of this project is it is a reference architecture for programs. 

The intent is for this code is to serve as a starter level blueprint for building cross platform visual programs in native code that are designed to function long-term. The design may not eliminate the need to understand the technologies to which you link. Rather, it gives you a structure in which several graphics and interactive technologies could be fitted to your solution.

WHAT THIS IS NOT:
------------------------------------------

This is not a replacement graphics stack. It has no connection with video games, simulations, or highly sophisticated user interfaces. Nothing other than a high level formula for applying other graphics and interactive platforms.

STATUS:
------------------------------------------

Fully operational. Efforts to refine it continue. Tested for use in Ubuntu-based Linux environments. No known impairments to operate in other environments. The only requirements are the dependent source code, a solid C++ compiler for a given environment to produce the canonical executables for those environments.

TECHNOLOGY:
------------------------------------------

The language is C++ for a one-to-one mapping between code and machine with access to an extensive predefined feature set.

SFML is the default technology used as a bridge to graphics and interactive functions. The included make file references SFML in a shared library configuration.

JSONCpp is used to translate JSON formatted data. It is fully compiled into the program.

C++ STL is applied to simplify code with production quality algorithms and data structures.

HOW IT STARTED:
------------------------------------------

A couple of articles show the transit of ideas that made this solution a useful concept to consider.

Build a C++ Cross Platform Program with Allegro
<a href="https://gautiertalksopentech.wordpress.com/2013/02/03/build-a-c-cross-platform-program-with-allegro/" target="_blank">article, 2/3/2013</a>

Exploring SFML Graphics in C++
<a href="https://gautiertalkstechnology.wordpress.com/2014/08/10/exploring-sfml-graphics-in-cplusplus/" target="_blank">article, 8/10/2014</a>

Build a Cross Platform C++ Program with SFML
<a href="https://michaelgautiertechnology.wordpress.com/2015/02/13/build-a-cross-platform-cplusplus-program-with-sfml/" target="_blank">article, 2/13/2015</a>

ORIGINAL AUTHOR
------------------------------------------
Michael Gautier can be reached on his <a href="https://michaelgautier.wordpress.com" target="_blank">WordPress</a> site.
