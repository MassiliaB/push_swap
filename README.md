# push_swap

(42 project) This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.
To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

**Instructions :**
You have 2 stacks, a and b :
  ◦ a contains a random number of either positive or negative numbers without
    any duplicates.
  ◦ b is empty
The goal is to sort in ascending order numbers into stack a. To do this you have 11 operations at your disposal, you can either swap the first two
numbers of a stack, you can push the first one to the other stack, you can rotate the stack so that the first element become the last one or you can
'reverse' rotate so that the last one become de first one.

You can test it by running :

`export arg=$(./genstack.pl 500) ; ./push_swap $arg`
