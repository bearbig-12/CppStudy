

//						�Լ�������(��������Լ�)				vs				����Լ��� ������
//	ǥ����				ret-type (*)(param-list)								ret-type(class-name::*)(param-list)
//	����				using fptr = int (*)(int x)								using fptr = int (Myclass::*)(int x)
//	���				fptr(3);												(intance.*fptr)(3);
