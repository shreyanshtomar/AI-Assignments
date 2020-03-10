# TSP
Travelling Salesman using A*

Initial State: Agent in the start city and has not visited any other city

Goal State: Agent has visited all the cities and reached the start city again

Successor Function: Generates all cities that have not yet visited

Edge-cost: distance between the cities represented by the nodes, use this cost to calculate g(n).

h(n): distance to the nearest unvisited city from the current city + estimated distance to travel all the unvisited cities (MST heuristic used here) + nearest distance from an unvisited city to the start city. Note that this is an admissible heuristic function.
