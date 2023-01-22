# Part  I: Class Design

Each  duelingJP  object  encapsulates  some  number  of  distinct jumpPrime  objects;  the  cardinality  of jumpPrime subobjectsvaries  across  duelingJP  objects.  The  key functionality  of  a  duelingJP  object  is  to manage  the  jumpPrime  subobjects  and  answer  client  queries  as  to  the number  of  “collisions”  and “inversions”.  
Two jumpPrime objects are said to “collide” if they produce the same prime number upon an up (or  down)  request.  For  example, if  active  jumpPrime  object  j1  encapsulates  2222,  and  jumpPrime  object  j2 encapsulates 2233, they both will produce 2221 for down()and 2237 for up().  
Two  jumpPrime  objects  are  said  to  be  “inversions”  if  they produce  the  same  prime  number  for complementary requests. For example, if active jumpPrime object j3 encapsulates 3519, and active jumpPrime object j4 encapsulates 3528, j4 produces 3527 for down()and j3 produces 3527 for up().

Deep copying must be supported and should be explicitly tested in the driver.
Move  semantics  must  be  supported  and  should  be  explicitly  tested  in  the  driver  by  the  use  of  smart pointers and an STL container. 

# Part II: Driver (p2.cpp)
Fulfill the testing requirements as specified in P1.

Additionally:
1) Do NOT use raw pointers
2) Demonstrate  your  understanding  of  smart  pointers  by using both  unique_ptr  and  shared_ptr instead of raw pointers to reference heap-allocated duelingJP  objects
3) Use a container from the STL; Add and remove heap-allocated duelingJP  objects to this container
4) Demonstrate copying of duelingJP  objects via call by value