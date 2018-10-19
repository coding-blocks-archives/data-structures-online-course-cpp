
//Circular Queue
class Queue{

	int cs;
	int ts;
	int f;
	int r;
	int *arr;

public:
	Queue(int ds=4){
		f = 0;
		cs = 0;
		ts = ds;
		r = ts-1;
		arr = new int[ds];
	}
	bool full(){
		return cs==ts;
	}

	void push(int data){
		if(!full()){
			r = (r+1)%ts;
			arr[r] = data;
			cs++;
		}
	}
	void pop(){
		if(!empty()){
			f = (f+1)%ts;
			cs--; 
		}
	}
	int front(){
		return arr[f];
	}
	bool empty(){
		return cs==0;
	}
};