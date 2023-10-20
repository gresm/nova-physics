<p align="center"><img src="https://raw.githubusercontent.com/kadir014/kadir014.github.io/master/assets/novaphysics.png" width=340></p>
<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-blue.svg">
  <img src="https://img.shields.io/badge/version-0.5.1-yellow">
  <a href="https://www.codacy.com/gh/kadir014/nova-physics/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=kadir014/nova-physics&amp;utm_campaign=Badge_Grade"><img src="https://app.codacy.com/project/badge/Grade/9556f3db17d54b288557d3b2e9dbf366"></a>
</p>
<p align="center">
Nova Physics is a lightweight and easy to use 2D physics engine.
</p>



# Features
- Simple and user-friendly interface
- Rigid body dynamics
- Iterative sequential impulse solver
- Semi-implicit (symplectic) Euler integrator
- Convex polygon, circle and AABB collisions
- Material properties (friction, restitution and density)
- Collision event callbacks
- Sleeping
- Attractive forces
- Portable codebase with no dependencies



# Future
Nova Physics is still in its early stages as in 0.x.x versions. There is a large room of improvement and optimization of the API and engine's itself. Here are some important points that needs a touch before reaching 1.x.x milestone:

#### Faster broad-phase
Current broad-phase strategy is a spatial hash grid, which works well in lots of cases but also supporting a BVH (bounding volume hierarchy tree) can be a good target for developers to choose for their cases.

#### Stability & Optimization
Other than a faster broad-phase, I will be working on general optimizations and refactoring the codebase. SIMD support and a multithreaded solver is also in the schedule but has low priority for obvious reasons.

#### Python Binding
Nova Physics's Python module ([here](https://github.com/kadir014/nova-physics-python)) is still WIP. I plan it to have an easy-to-use Pythonic interface. Other language binding contributions are also welcome!



# Installing & Building
Nova Phyiscs is lightweight and portable, using only C standard library.
<br><br>
Development libraries are always shipped with the most recent release under the name of `nova-physics-X.X.X-devel.zip` or `.tar.gz`. You can download the archive [here](https://github.com/kadir014/nova-physics/releases) and link `libnova.a` to use Nova Physics in your project.
<br><br>
But if you want (*or need*) to build Nova Physics from scratch on your own, use [the building guide](https://github.com/kadir014/nova-physics/blob/main/BUILDING.md#building-nova-physics-library).



# Examples

<img src="https://raw.githubusercontent.com/kadir014/nova-physics/main/examples/assets/examplegif.gif" width=400>

Example demos are in [examples](https://github.com/kadir014/nova-physics/blob/main/examples/) directory, use [the example building guide](https://github.com/kadir014/nova-physics/blob/main/BUILDING.md#running-examples-on-windows) to run examples.



# Documentation
You can access the documentations [here](https://nova-physics.rtfd.io).



# Resources & References
- **Erin Catto**, [GDC Presentations](https://box2d.org/publications/)
- **Chris Hecker**, [Rigid Body Dynamics](https://chrishecker.com/Rigid_Body_Dynamics)
- **Randy Gaul**, [Game Physics Articles](https://tutsplus.com/authors/randy-gaul)
- **Allen Chou**, [Physics Blogs](https://allenchou.net/category/physics/)
- **Marjin Tamis** & **Giuseppe Maggiore**, [Constraint Based Physics Solver](http://mft-spirit.nl/files/MTamis_ConstraintBasedPhysicsSolver.pdf)
- **Micheal Manzke**, [Multiple Contact Resolution](https://www.scss.tcd.ie/~manzkem/CS7057/cs7057-1516-10-MultipleContacts-mm.pdf)
- **Dirk Gregorius**, [Robust Contact Creationg for Physics Simulations](http://media.steampowered.com/apps/valve/2015/DirkGregorius_Contacts.pdf)
- **Andrew Sevenson**, [Separating Axis Theorem Explanation](https://www.sevenson.com.au/programming/sat/)



# License
[MIT](LICENSE) © Kadir Aksoy
