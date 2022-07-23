//STACKS - LIFO (Last in First out)
stack<int> st;
    st.push(1);

   //functions   O(1)
push(x) // Adds the element ‘x’ at the top of the stack 
pop() // Deletes the TOP/last most element of the stack 
top() // Returns a reference to the top most element of the stack 

empty() // Returns whether the stack is empty 
size() // Returns the size of the stack 

//QUEUE - FIFO (First in First out)
queue<int> q;
    q.push(10); q.push(20);  q.push(30);  // 10 20 30

q.front() //return 10   (first element)
q.back()  //return 30   (last element)

q.pop()   //removes 10  (first element)




   //functions   O(1)
push(g)  // push() function adds the element ‘g’ at the end of the queue.
pop()  // pop() function deletes the FIRST element of the queue.

front() // front() function returns a reference to the first element of the queue.
back() // back() function returns a reference to the last element of the queue.

size()  // Returns the size of the queue.
empty()  // Returns whether the queue is empty.

swap() //in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
emplace() //in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.

