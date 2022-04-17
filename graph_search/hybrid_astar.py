def expand(state, goal):
    next_states = []
    for delta in range(-35, 40, 5):
        # create a trajectory with delta as steering angle using
        # the bicycle model:

        # Begin bicycle model
        delta_rad = deg_to_rad(delta)
        omega = SPEED/LENGTH * tan(delta_rad)
        next_x = state.x + SPEED * cos(theta)
        next_y = state.y + SPEED * sin(theta)
        next_theta = normalize(state.theta + omega)
        # End bicycle model

        next_g = state.g + 1
        next_f = next_g + heuristic(next_x, next_y, goal)

        #Create new state object with all of the "next" values
        state = State(next_x, next_y, next_theta, next_g, next_f)
        next_states.append(state)
    
    return next_states

def search(grid, start, goal):
    #Keeps track of the stack of states objects we are searching through
    opened = []

    #3d array of zeros with dimensions:
    # (NUM_THETA_CELLS, grid_x size, grid_y size)
    closed =    [
                    [ 
                        [0 for x in range(grid[0])] for y in range(len(grid)) 
                    ] for cell in range(NUM_THETA_CELLS)
                ]

    # 3D array with same dimensions. Will be filled with State() objects 
    # to keep track of the path through the grid. 
    open =    [
                    [ 
                        [0 for x in range(grid[0])] for y in range(len(grid)) 
                    ] for cell in range(NUM_THETA_CELLS)
                ]
    
    #Create new state object to start the search with:
    x = start.x
    y = start.y
    theta = start.theta
    #Calculate cost
    g = 0
    f = heuristic(start.x, start.y, goal)
    state = State(x, y, theta, 0, f)
    opened.append(state)

    # The range from 0 to 2pi has been discretized into NUM_THETA_CELLS cells. 
    # Here, theta_to_stack_number returns the cell that theta belongs to. 
    # Smaller thetas (close to 0 when normalized  into the range from 0 to 
    # 2pi) have lower stack numbers, and larger thetas (close to 2pi when 
    # normalized) have larger stack numbers.
    stack_num = theta_to_stack_number(state.theta)
    closed[stack_num][index(state.x)][index(state.y)] = 1

    # Store our starting state. For other states, we will store the previous 
    # state in the path, but the starting state has no previous.
    came_from[stack_num][index(state.x)][index(state.y)] = state

    #While there are still states to explore
    while opened:
        #sort the states by f-value and start search using the state with
        # the lowest f-value. This is crucial to the A* algorithm;
        opened.sort(key=lambda state:state.f)
        current = opened.pop(0)

        #Check if the x and y coordinates are in the same grid cell
        # as the goal. (Note: the idx function returns the grid index
        # for a given coordinate)
        if (index(current.x) == goal[0]) and (index(current.y) == goal.y):
            # If so, the trajectory has reached the goal.
            return path
        
        #Otherwise, expand the current state to get a list of possible
        # next states
        next_state = expand(current, goal)
        for next_s in next_states:
            # if we have expanded outside the grid, skip this next_s
            if next_s not in grid:
                continue
            # Otherwise, check that we haven't already visited this cell and 
            # that there is not an obstacle in the grid there
            stack_num = theta_to_stack_number(next_s.theta)
            if closed[stack_num][index(next_s.x)][index(next_s.y)] == 0
                and grid[index(next_s.x)][index(next_s.y)] == 0:

                #the state can be added to the open stack
                opened.append(next_s)

                #The stack number, idx(next_s.x), idx(next_s.y) tuple 
                # has now been visited, so it can be closed
                closed[stack_num][idx(next_s.x)][idx(next_s.y)] = 1
                # The next_s came from the current state, and is recorded.
                came_from[stack_num][idx(next_s.x)][idx(next_s.y)] = current


