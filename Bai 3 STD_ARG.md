## 1. Macro function
    là macro hoạt động như 1 hàm, được định nghĩa bằng #define
    Nó sẽ thay thế nội dung mà nó định nghĩa tại thời điểm biên dịch
    Các dòng của hàm được định nghĩa bên trong macro sẽ kết thúc bằng dấu \
## Ví dụ cách định nghĩa và gọi hàm thông qua macro   
    #include <stdio.h>   
    #define CREATE_FUNC(name, arg) \
    void name()                \
    {                          \
        printf(arg);           \
    }

    CREATE_FUNC(test1, "Duy Pham");   
    CREATE_FUNC(test2, "Hoang Le");   
    CREATE_FUNC(test3, "Nhat Le");   
    /*   
    được thay thế bằng các dòng dưới đây tại thời điểm biên dịch   
    void test1() { printf("Duy Pham"); };   
    void test2() { printf("Hoang Le"); };   
    void test3() { printf("Nhat Le"); };   
    */   
    int main()   
    {   
        test1();  
        test2();  
        test3();   
        return 0;  
    }  
## 1.1 Macro nối chuỗi
Macro sử dụng toán tử ##, cho phép ghép các phần tử lại với nhau.
Note: giá trị khi truyển vào macro là các ký tự không nằm trong dầu nháy kép "" khai báo  

    #define COMCATE(name1, name2) \
        char*sen_sor_##name2; \
        int data_##name1; \
Sử dụng

    #include <stdio.h>
    int main(){
        COMPATE(65, Temp); //Thay thế bằng char *sensor_Temp; int data_65;
        return 0;
    }

## 1.2 Macro chuẩn hoá chuỗi từ text
Macro này sử dụng toán từ #, cho phép ta chuẩn hoá từ 1 dãy các ký từ truyền vào thành chuỗi.
Khai báo   

    #define STRING_CONVERT(str) printf(#str)

Sử dụng

    #include <stdio.h>
    int main(){
        STRING_CONVERT(Nguyen Manh Dung); //kết quả in ra chuỗi Nguyễn Mạnh Dũng
        return 0;
    }

## 1.3 Macro varidic
* Macro cho phép định nghĩa các đối số truyền vào số lượng không cố định, có nghĩa là bao nhiêu cũng được
* Nó được định nghĩa bằng cách sử dụng dấu ... để thể hiện các tham số sẽ nhận vào

ví dụ: Tạo ra macro để định nghĩa 1 hàm tính tổng các đối số truyền vào với số lượng tuỳ ý

    #define SUM(...)                    \
        int arr[] = {__VA_ARGS__, 0);   \
        int i = 0;                      \
        int tong = 0;                   \
        while (arr[i] != 0)             \
        {
            tong += arr[i++]            \
        }                               \
        printf("tong: %d\n", tong);     \

    int main()
    {
        SUM(22, 33, 44);
        return 0;
    }

## 2. Thư viện STDARD
Đây là thực viện cung cấp các macro để thao tác và xử lý danh sách chứa các biến đối số

## 2.1 Các macro phố biến sử dụng trong STDARG
* va_list: Định nghĩa 1 biến để lưu trữ danh sách các đối số ở dạng chuỗi.
* va_start: Xác định điểm bắt đầu của biến lưu danh sách để xử lý
* va_arg: lấy ra đối số hiện tại mỗi lần gọi
* va_copy: trỏ và địa chỉ các đối số trong biến danh sách
* va_end: giải phóng biến lưu trữ danh sách
## 2.2 Cách sử dụng để thao tác với 1 danh sách đối số
a) Khi biết trước kích thước    
![image](https://github.com/user-attachments/assets/6dd8fde0-05ef-4990-b95b-26d6ae06f3b6)   

b) Khi sử dụng giá trị để xác định điểm dừng của danh sách  
![image](https://github.com/user-attachments/assets/faecfafd-b34c-45c9-af95-10a1a294832a)   

c) Sử dụng pointer để xác định điểm dùng của danh sách

        #include <stdio.h>
        #include <stdarg.h>

        #define tong(...) sum3(__VA_ARGS__, '\n')

        int sum3(int begin, ...){
            va_list list; //save input arguments
            va_list check; // pointer to check variable of list

            va_start(list, begin);
            /*
            *@param: first: pointer used to loop through every argument in list
            *         second: list contains input arguments
            */
            va_copy(check, list);

            int result = count; //save the first element to result

            int value = 0;
            while(va_arg(check,char*) != (char*)'\n'){ // nếu gặp ký tự kết thúc thì dùng xử lý
                                                        // -> vì biến thuộc kiểu char*
                result += va_arg(list, int);
            }
            va_end(list);
            return result;
            
        }
        int main(){
            int total = tong(12, 0, 11, 0, 15);
            printf("total: %d, total);
            return 0;
        }
d) Được định nghĩa trong 1 struct

![image](https://github.com/user-attachments/assets/5c96f887-1b1a-497a-bb03-7f3f8b9225ba)

## 3 Thư viện ASSERT    
    Đây là thư viện cung cấp các hàm giúp ta thiết kế các mã lỗi để giúp cho quá trình debug 
    và sửa lỗi nhanh chóng hiệu quả. Với các tính năng như:
        - Nó cho ta biết đó là loại lỗi gì? nằm ở đâu trong chương trình?
        - Dừng hẳn chương trình nếu phát hiện lỗi.
## 3.1 Cách sử dụng 
### a) Kiểm tra giá trị có hợp lệ
Sử dụng trực tiếp hàm assert
```c
#include<assert.h>
#include<stdio.h>

double divide(int mau,int tu){
    assert(mau != 0 && "mau phai khac 0"); //nội dung bên trong sẽ được in ra nếu giá trị không hợp lệ
    return (double)mau/tu;
}
int main(){
    double result = divide(0,21); 
    printf("%.2f",result);
}
