# CSES Problem Set Solutions

## Trees
 - [Subordinates](https://cses.fi/problemset/task/1674/)
 - [Tree Diameter](https://cses.fi/problemset/task/1131/)
 - [Tree Distances I](https://cses.fi/problemset/task/1132/)
 - [Tree Distances II](https://cses.fi/problemset/task/1133/)
 - [Company Queries I](https://cses.fi/problemset/task/1687/)
    - The basic idea behing binary lifting.
        - assumption 1) the tree is connection in a way `1 -> 2 -> 3 -> 4 -> ... -> n`.
        ```txt
        pre-compute that table
         for if i want to finx for any x that is power of 2 (1, 2, 4, 8, 16, 32)
         we can caluclate tha answer for them in a way that starts from  ( 1+1, 2 + 2, 4 + 4, 8 + 8)
         for n[x][i] = n[x][i-1] + [n[x][i-1]][i-1]
         ```
 - [Company Queries II](https://cses.fi/problemset/task/1688/)
    - make the two nodes equal using binary lifting and finally find their parent using binary lifting.
    - we can do this by checking their greatest parent `i` for both nodes, if they are not equal it means i can make the transition u = table[u][i] and v = table[u][i]
 - [Distance Queries](https://cses.fi/problemset/task/1135/)
    - calculate LCA if they are at the same path it's just different between the two nodes depth.
    - if there is another node that is their LCA it is the distance from a to LCA node + the distance from LCA node to b.
    - keep that in mind populate the LCA iterating parent's wise it means outet loop is going to be to parent, grand_parent ... and the inner loop is the node.
    - this way we can avoid dependencies.

