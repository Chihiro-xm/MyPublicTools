﻿// MyPublicTools.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "stdafx.h"

//MyMutex m_writeLock;
//MyMutex m_writeLock2;
//
//Semaphore sam(0);
//int abcc = 0;
//
//class Example1 : public Thread
//{
//public:
//	//重写Run;
//	
//	void Run() override
//	{
//		//InstanceMutex MySystemMutex(L"mylock",TRUE);
//		int a = 0;
//
//		
//		while (this->bRun)
//		{
//			//sam.signal();
//			printf("Hello thread1\n");
//			//Sleep(1000);
//			a++;
//			
//			//m_writeLock.Lock();
//			//MySystemMutex.CreateInstanceMutex();
//			//int ddd = abcc;
//			//ddd++;
//			Sleep(30);
//			//abcc=ddd;
//			abcc++;
//			cout << abcc << endl;
//			//MySystemMutex.DeleteInstanceMutex();
//			//m_writeLock.Unlock();
//			if (a == 100)
//			{
//				
//				break;
//			}
//			
//		}
//	}
//};
//
//class Example2 : public Thread
//{
//public:
//	//重写Run;
//	void Run()
//	{
//		int a = 0;
//
//		sam.wait();
//		while (this->bRun)
//		{
//
//			printf("Hello thread2\n");
//			//Sleep(1000);
//			a++;
//			
//			//m_writeLock2.Lock();
//			//m_writeLock.Lock();
//			Sleep(30);
//			abcc++;
//			cout << abcc << endl;
//			//m_writeLock2.Unlock();
//			//m_writeLock.Unlock();
//			
//			if (a == 100)
//				break;
//		}
//	}
//};
//
//int main()
//{   //https://blog.csdn.net/qq_40945965/article/details/86831178
//    //https://www.cnblogs.com/happykoukou/p/6307257.html
//    //https://www.cnblogs.com/whwywzhj/p/8478628.html
//
//
//    //CHttpDownload abc;
//    //abc.DownloadToFile(L"https://tools.skylarqa.com/test/yuanchunming/csv数据处理.zip?download=true",L"C:\\Users\\yuanchunming01\\Desktop\\MyPublicTools\\123.html");
//
//	//Wcout(GetFileNameFromPath(L"C:\\Users\\yuanchunming01\\Desktop\\MyPublicTools\\新建文件夹\\999.txt.111", true));
//	CString abc;
//	GetIniValue(abc, L"XshellOptions", L"MouseRightButton", L"C:\\Users\\yuanchunming01\\Desktop\\MyPublicTools\\Xshell.ini");
//
//	//Example1 e1,e3,e4;
//	//Example2 e2;
//
//	//启动线程;
//	//e1.Start();
//	//e2.Start();
//	//e3.Start();
//	//e4.Start();
//	//e2.Start();
//	//getchar();
//	//cout << abcc << endl;
//	system("pause");
//
//
//	//InstanceMutex abc(L"mysuo");
//	//abc.CreateInstanceMutex();
//	//system("pause");
//	//abc.DeleteInstanceMutex();
//	//system("pause");
//
//
//}

class abc
{
public:
     virtual void taskFunc(void* arg)
    {
        int num = *(int*)arg;
        cout << "thread: " << "number=" << num << endl;
        Sleep(1000);
    }
};




class abd :public abc
{
public:
    void taskFunc(void* arg)
    {
        int num = *(int*)arg;
        cout << "thread: " << "number=" << num+1 << endl;
        Sleep(2000);
    }
};




void taskFunc2(void* arg)
{
    int num = *(int*)arg;

    Sleep(3000);
    cout << "thread: " << "number=" << num << endl;
}


int func(int x)
{
    int countx = 0;
    while (x)
    {
        countx++;
        x = x & (x - 1);
    }
    return countx;



        
}
int main()
{
    /*int* num = new int(100);
    abc* ddd = new abd();
    ddd->taskFunc(num);*/

    abc* aaa = new abc();

    ThreadPool pool(0,2);
    int i;
    for (i = 0; i < 10; ++i)
    {
        int* num = new int(i + 100);
        pool.addTask(taskFunc2, (void*)num);
        Sleep(1000);
    }


    //int* num = new int(100);
    //pool.AddTask(taskFunc2, (void*)num);


    //while (true)
    //{
    //    int i = 0;
    //    int a = 0;
    //    cin >> a;
    //    if (a == 1)
    //    {
    //        int* num = new int(i + 100);
    //        pool.addTask(taskFunc2, (void*)num);
    //    }
    //}

    //for (; i < 200; ++i)
    //{
    //    Sleep(1);
    //    int* num = new int(i + 100);
    //    pool.AddTask(taskFunc2, (void*)num);
    //}


    //int abc = func(9999);

    getchar();
    return 0;
}