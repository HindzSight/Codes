class Stack{
	protected int top;
	protected int[] arr;
	protected int s;

	public Stack(int size){
		top = -1;
		s= size;
		arr = new int[s];
	}
	public boolean isEmpty(){
		if(top == -1) return true;
		return false;
	}
	public void push(int val){
		if(isEmpty()){
			top = 0;
			arr[top] = val;
		}else if(top == (s-1)){
			System.out.println("STACK OVERFLOW");
		}else{
			top++;
			arr[top] = val;

		}
	}
	public int pop(){
		if(top == -1){
			System.out.println("STACK UNDERFLOW");
			return -1;
		}
		else{
			int temp = arr[top];
			top--;
			return temp;
		}
	}
	public int peek(){
		if(top == -1){
			return -1;
		}
		else{
			return arr[top];
		}
	}
	public void display(){
		for(int i = 0 ; i < top + 1 ; i++){
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
}
public class ResizableStack extends Stack{

	public ResizableStack(int cap){
		super(cap);
	}
	public void push(int val){
		if(isEmpty()){
			top = 0;
			arr[top] = val;
		}else if(top == (s-1)){
			System.out.println("STACK OVERFLOW");
		}else{
			top++;
			arr[top] = val;
		}
	}
	public int capacity(){
		return s;
	}

	public void resize(int newCapacity){
		int[] newarr = new int[s];
		for(int i = 0 ; i < s ; i++){
			newarr[i] = arr[i];
		}
		arr = new int[newCapacity];
		for(int i = 0 ; i < s ; i++){
			arr[i] = newarr[i];
		}
		s = newCapacity;
	}

	public static void main(String[] args) {
		
		ResizableStack rS = new ResizableStack(5);
		rS.push(12);
		rS.push(112);
		rS.push(1232);
		rS.push(17435);
		rS.push(89890);
		rS.display();
		System.out.println("Capacity :"+rS.capacity());
		rS.resize(10);
		System.out.println("Capacity :"+rS.capacity());
		rS.display();
		rS.push(69);
		rS.display();
		// Stack s = new Stack(5);
		// System.out.println(s.peek());
		// s.push(123);
		// s.push(12);
		// s.push(2323);
		// s.push(565);
		// s.push(190);
		// // s.push(100);
		// s.display();
		// System.out.println("\nPopped Val : "+s.pop());
		// System.out.println("Peek : "+s.peek());
		// s.display();
	}
}