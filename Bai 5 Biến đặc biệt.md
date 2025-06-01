  # 1 Từ khoá extern
Được sử dụng để thông báo cho compiler biết 1 biến được gọi và sử dụng trong file hiện tại đã dược khai báo báo ở file và không cần thiết
phải định nghĩa lại
## Bản chất
Từ khoá extern cho phép 1 tài nguyên chung được chia sẻ và sử dụng trong nhiều file của chương trình.
- file lib.c
```c
int a = 34;
```
- file main.c
```c
extern int a;
int main(){
  printf("%d", a);
  return 0;
}
```
## gọi 1 hàm trong file khác.
Đối với việc gọi 1 hàm vào đó, từ 1 file khác thì ta không cần sử dụng từ khoá static mà sử dụng trực tiếp trong file main hiện tại.
- file output.c
```c
#include <stdio.h>
int sensor = 34;
void printdata(int sensor){
  printdata(sensor); //sử dụng  hàm
  return 0;
}
```
- file main.c
```c
 #include<stdio.h>
 void printdata(int); // khai báo function prototype 
 extern int sensor;   // gọi biến từ file khác 
 int main(){
    printdata(sensor); //sử dụng hàm
    return 0;
 }
```

# Từ khoá static
## Static local
1 biến sẽ được cấp phát vùng nhớ tồn tại xuyên suốt thời gian chạy chương trình và phạm vi sử dụng bên trong 1 hàm.
  - Ta có thể sử dụng biến static để thực hiện cập nhật giá trị của 1 dữ liệu nào đó môi khi gọi hàm (vùng nhớ không bị giải phóng khi ra
  khỏi phạm vi định nghĩa).
  ```c
  #include<stdio.h>
 void update(int count){
    static int data = 25; 
    printf("lan %d = %d\n",count,data++);
 }
```
  - Trong hàm update ta tạo ra 1 biến static với giá trị ban dầu là 25 và in ra giá trị của nó đòng thời tăng lên 1 đơn vị, với tham số count
  sẽ đếm số lần hàm được gọi thông qua đối số truyền vào trong hàm main.
  ```c
  int main(){
    for(int i = 0 ; i < 5 ; i++){
         update(i + 1);
    }
    return 0;
  }
```
  - ở trong hàm main ta dùng 1 vòng lặp for để chạy chương trình với số lần nhật định và truyền vào đối số i + 1 cho biến số lần in ra hiện tại
    của hàm update. Thực hiện chạy chương trình ta có kết quả:    
    ```c
    lan 1 = 25
    lan 2 = 26
    lan 3 = 27
    lan 4 = 28
    lan 5 = 29
    ```
    
