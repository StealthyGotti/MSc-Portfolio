## Assignment: Linear Least Squares Optimization via Gradient Descent

This assignment focuses on solving a Linear Least Squares minimization problem using the Gradient Descent optimization algorithm. Instead of using direct analytical solvers, the objective is to iteratively find the optimal vector $x$ that minimizes the quadratic loss function of a linear system, simulating standard workflow procedures for convex optimization problems in low-dimensional and scalable spaces.

### Tasks Overview

* **Problem Formulation and Parameters**: Define a low-dimensional structural framework with a matrix $A \in \mathbb{R}^{2 \times 2}$ and a vector $b \in \mathbb{R}^{2}$. This setup is selected to allow a clear geometric interpretation, though the implementation is dynamically scalable to higher dimensions.
* **Objective Function and Calculus**: Implement the objective function to be minimized, formulated as $f(x) = \frac{1}{2}\|Ax-b\|_2^2$. Derive its exact gradient vector through standard matrix calculus rules, defined as $\nabla f(x) = A^T(Ax-b)$, to guide the step direction.
* **Surface Visualization**: Generate a 3D surface plot of the convex cost function using a meshgrid configuration. This visual aid maps the optimization landscape, explicitly showing the global minimum bowl shape for verification.
* **Hyperparameter Tuning**: Initialize the core hyperparameter constraints of the iterative solver, specifically setting the learning rate (step size $\alpha$) and the convergence metrics: the gradient norm threshold ($TOL\_GRAD\_NORM$), the update distance threshold ($TOL\_DIST$), and the maximum allowed iterations ($MAX\_ITER$).
* **Optimization and Convergence Loop**: Execute the core optimization loop from a fixed initialization point. In each step, compute the next iterate using the gradient descent update rule, evaluate both stopping criteria, and systematically store the historical path of the estimates.
* **Trajectory Tracking**: Superimpose the full sequential optimization path onto the 3D landscape plot. This final visualization tracks the algorithmic trajectory from the starting point directly down to the globally optimal solution.