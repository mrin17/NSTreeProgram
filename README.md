# NSTreeProgram
Creates a tree based on the number of levels and the rule set I was given


To compile and run:
I used Visual Studio 2015. The new version of Unity comes with Visual Studio (with a C# compiler, but the C++ one can be downloaded from the Visual Studio website). Open Visual Studio, click Open->Project, open TreeProgram.sln, and then click Local Windows Debugger (or whatever debugger it says next to the green arrow). To open the .cpp file, find the directory of that solution file, then click the folder TreeProgram, and the file is TreeProgram.cpp. I will include a .cpp file without the '#include "stdafx.h"' because I have encountered problems with this. To use UNIX, locate the file TreeProgram.cpp and use 'g++ TreeProgram.cpp'.

How the script works, how the code is organized:
There are 3 classes: Node, TreeNode, and EmptyNode
Node - abstract class that has virtual functions to be implemented by Node and EmptyNode.

TreeNode - Inherits from Node. A tree node with a left Node, a right Node, and a value. If the TreeNode has no children, the left Node and right Node are EmptyNodes. The TreeNode  has other values it stores, such as a string telling us if it is a left or right child, and its partner. A Node's partner node is (as I am defining it) the other child of your parent. 

EmptyNode - Inherits from Node. An empty node. Does not have any data. I use this class so I don't have to check if a Node is null before I call a method on it. 

The main method prompts for input, and then, if given a valid number X larger than zero, creates a TreeNode and tells the TreeNode to create a tree with X levels. The TreeNode creates left and right nodes (it makes them EmptyNodes if this is the last level, or TreeNodes if this is not). If those nodes are not EmptyNodes, it assigns them a string ("L" or "R") to determine if those nodes are a left node or a right node. It then assigns each TreeNode's partner to the other TreeNode (I'll get to the reasoning behind this in just a second). Then, after assigning values to the TreeNodes, it tells both TreeNodes to create a tree with one less level (because we just added this level). Last, the tree is printed out in parenthesis form. 

The calculation was interesting. I originally decided to use a mirror approach, because the tree was mirrored from the start position on the Y axis, but I came to realize the code was smoother and it looked neater if I did not do this. Besides, I came up with a simple solution for the numbering problem. I recognized that 1s were lining the sides, and that does not change. I also recognized that each non-partner neighbor has the same value. Basically, if you are next to a node, and that node does not have the same parent that you do, your values are the same. I used this to my advantage when creating the rules system for this tree: 

If a Node is a left child, its left neighbor has its value (unless it is a 1, in which case it has no left neighbor)

If a Node is a left child, its right neighbor has its partner's value.

If a Node is a right child, its left neighbor has its partner's value.

If a Node is a right child, its right neighbor has its value (unless it is a 1, in which case it has no right neighbor)

I used these rules, and the assignment became very easy to code. When a TreeNode assigns values to a left node, it adds its value to its left neighbor's value. When a TreeNode assigns values to a right node, it adds its value to its right neighbor's value. These values are determined by the rules listed above













