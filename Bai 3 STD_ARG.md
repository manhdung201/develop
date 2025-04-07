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

