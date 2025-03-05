void MyQueue ::push(int x) {
    // Your Code
    //rear++;
    arr[rear]=x;
    rear++;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    if(front==rear){
        return -1;
    }else{
    return arr[front++];
    }
    
}
