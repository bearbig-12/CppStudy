

//						함수포인터(정적멤버함수)				vs				멤버함수의 포인터
//	표현식				ret-type (*)(param-list)								ret-type(class-name::*)(param-list)
//	예제				using fptr = int (*)(int x)								using fptr = int (Myclass::*)(int x)
//	사용				fptr(3);												(intance.*fptr)(3);
