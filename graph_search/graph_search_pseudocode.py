def computeShortestPath(s_start, s_goal):
    g_cost[s_start] = 0
    parent[s_start] = s_start

    #TO VISIT
    openlist = []
    openlist.insert(s_start, g_cost[s_start] + h_cost[s_start])
    
    #VISITED
    closedlist = []

    while not openlist.empty():
        s = open_list.pop()
        if s == s_goal:
            return "path found"
        
        closedlist.push(s) #mark as visited
        for s_ in neighbor(s):
            if s_ not in closedlist: #if not visited
                if s_ not in openlist: #if not in TO VISIT list
                    g_cost[s_] = inf;
                    parent[s_] = NULL;
                    updateVertex(s, s_)
    
    return "no path found"

def updateVertex(s, s_):
    #Only visit s_ if the current path's cost is less than what's recorded
    if (g_cost[s] + cost(s, s_) < g_cost[s_]):
        g_cost[s_] = g_cost[s] + cost(s, s_)
        parent[s_] = s
        if s_ in openlist:
            openlist.remove(s_)
        openlist.insert(s_, g_cost[s_] + h_cost[s_])

