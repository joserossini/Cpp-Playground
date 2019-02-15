#include <functional>

class CallBack
{
	public:
		CallBack() {};
		void addCall(std::function<void(int*)> call){
			_call = call;
		}
		void executeCall(int * i) {
			_call(i);
		}
	private:
		std::function<void(int*)> _call;
};

class CallBackCenter
{
	public:
		CallBackCenter(){};
		void addCallBack(CallBack *callBack){
			_callBack = callBack;
		};
		void run(){
			int * i = new int(10);
			_callBack->executeCall(i);
		};
		
	private:
		CallBack *_callBack;
};

class MyClass
{
	public:
		MyClass(CallBackCenter  & center):_callBack(new CallBack) {
			_callBack->addCall(std::bind(&MyClass::printInt,this,std::placeholders::_1));
			center.addCallBack(_callBack);
		};
		
		void printInt(int * i) {
			printf("%d",*i);
			}
		
	private:
		CallBack * _callBack;
};

int main ()
{
	
		CallBackCenter call = CallBackCenter();
		MyClass myclass = MyClass(call);
	
		call.run();
	
	return 0;
}


