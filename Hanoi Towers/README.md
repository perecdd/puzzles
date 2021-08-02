The main idea of puzzle that need to transfer all disks from one rod to one other. The difficulty is that you can only grab and transfer one top disk of every rod at the same time. In addition, you can not put a larger disk on a smaller one.

The solution presented in this repository solves the standard version of the puzzle with 3 rods and 8 disks. The algorithm is implemented using a recursive procedure and passes in 4 stages: (For clarity, we will call the rod from which we start - "current", the one where we should move the tower - "target", the last one, the auxiliary one - "buffer").

1) Checking the size. If there is only one disk left, then we finish the procedure.
2) Using the same function, we move a tower of the size of this - 1 to the buffer.
3) We have the lowest element left, which we move to the target rod.
4) We move the remaining top of the tower from the buffer to the target rod.

More information about Hanoi Towers you can find here: https://en.wikipedia.org/wiki/Tower_of_Hanoi