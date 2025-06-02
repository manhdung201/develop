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

## Static global và stactic function
Điều này cho biết biến hoặc hàm đó chỉ có thể gọi và sử dụng trong file hiện tại mà không thể hỏi thông qua các file nhằm giới hạn quyền truy cập và 
đảm bảo biến hoặc hàm đó không thể thay đổi ngoài phạm vi cho phép. Ví dụ ta viết chương trình tính toán 2 phân số như sau:

```c
typedef struct{
    int mauso;
    int tuso;
}phanso;
static phanso nhan2ps(phanso ps_a,phanso ps_b);
void print(phanso ps_a,phanso ps_b);
```
trong file trên ta tạo ra 1 struct để định nghĩa các thành phần của phân số và khai báo các function prototype
- file calculation.c
```c
#include"lib.h"
#include<stdio.h>
static phanso nhan2ps(phanso ps_a,phanso ps_b){
    phanso sum;
    sum.mauso = ps_a.mauso * ps_b.mauso;
    sum.tuso = ps_a.tuso * ps_b.tuso;
    return sum;
}

void print(phanso ps_a,phanso ps_b){
    phanso ketqua = tinhtoan(ps_a,ps_b);
    printf("%d/%d * %d/%d = %d/%d",
                            ps_a.mauso,ps_a.tuso,
                            ps_b.mauso,ps_b.tuso,
                            ketqua.mauso,ketqua.tuso);
}
```
trong file trên ta định nghĩa 2 hàm, với 1 hàm dùng để tính toán và 1 hàm để hiện thị kết quả được gọi trong chương trình chính cùng
với các đối số truyền vào.
- file main.c
```c
#include"lib.h"
int main(){
    phanso psa = {23,21};
    phanso psb = {35,27};
    print(psa,psb);
    return 0;
}
```
trong hàm trên ta đã khai báo 2 phân số và truyền vào hàm print để in ra kết quả nhung ko thể gọi tới hàm nhân 2ps để xem được cụ thể bên trongg.

# Register
Sử dụng khi ta muốn lưu trữ 1 biến nào đó trong thanh ghi của CPU thay vì trên RAM, mục đích là để tăng tốc độ tính toán và xử lý
```c
#include<stdio.h>
#include<time.h>
int main(){
    //gán thời gian bắt đầu
    clock_t start = clock();

    //khai báo biến để kiểm tra
    register int data = 0;

    //thực hiện công việc nào đó
    for( ;data < 5000000;data++);

    //gán thời gian kết thúc
    clock_t end = clock();
    
    //in ra thời gian xử lý 
    double time_differece = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("time : %f",time_differece);

    return 0;
}
```
Hàm trên sẽ đo thời gian thực thi của vòng lặp đối với biến i khi  khai báo là register. Nếu ta không khai báo biến i là register thì khi in ra kết quả sẽ
có sự chênh lệch thời gian. Trong trường hợp khai báo là register thì khi in ra kết quả thời gian sẽ nhỏ hơn khi không khai báo register.


# volatile
## Định nghĩa
Được sử dụng trên những biến thay đổi ngoài ý muốn của chương trình. Mục đích là để tránh việc compiler hiểu nhiều những biến này không dược cập nhật trong
khoảng thời gian nhất định và thực hiện xoá nó đi để tới ưu hoá chương trình chẳng hạn như trong các trương hợp xử lý sau:
- Phần cứng: thanh ghi của thiết bị thanh ghi
- Ngắt: Biến được câph nhật khi có tín hiệu tác động đến từ trong/ngoài vi điều khiển.
- Đa luồng: biến được truy cập hoặc thay dổi bởi 1 luồng khác.

## Bản chất
Từ khoá volatile đảm bảo rằng mỗi lần truy cập, giá trị mới nhất của biến được lấy trực tiếp từ RAM, thay vì dùng giá trị lưu trên thanh ghi

## Tối ưu hoá chương trình là gì ? cách ngăn chặn?
### + Đinh nghĩa
Đó là cơ chế giảm tải hoạt động cho chương trình khi nó giả định 1 biến sẽ không thay đổi giá trị trừ khi nó dược sửa trong thanh ghi. Nếu compiler thấy biến 
ko thay đổi trong logic của chương trình, nó có thể bỏ qua việc đọ giá trị biến từ bộ nhớ chính.

### + Tác động của volatile
Khi từ khoá này được khai báo, nó sẽ báo cho compiler biết rằng giá trị của biến có thể thay đổi bất ký lúc nào mà yêu cầu:
  - Không tối ưu hoá: bắt buộc đọc lại giá trị biến từ bộ nhớ chính
  - Luôn đọc giá trị trực tiếp từ bộ nhớ chính: compiler phải đọc giá trị mới nhất từ bộ nhớ thay vì dùng giá trị đã lưu trong thanh ghi.

### + Ứng dụng cụ thể.
Giả sử ta có 1 hệ thống nhúng điều khiển bởi 1 nút nhấn được cấu hình ngắt ngoài. Mỗi khi nhấn nút, thì sẽ có tín hiệu ngắt được phát hiện bởi vdk và 1 biến trạng
thái sẽ dược dùng để lưu sự kiện ngắt này. Trong chương tình chính sẽ xử lý những công việc dưa trên giá trị của biến.

#### Định nghĩa và khai báo biến cần thiết.
```c
#include <stdio.h>
#include <stdbool.h>

// Biến cờ được cập nhật bởi ngắt
volatile bool button_pressed = false; // Khai báo volatile vì biến này thay đổi ngoài vòng lặp chính
```


    
