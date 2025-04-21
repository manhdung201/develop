# 1. Khái niệm
  Đây là kĩ thuật để thao tác với giá trị các bit của 1 số ở dạng nhị phân, mục đích để lưu trữ  
  nhiều tính năng bằng trạng thái của các bit. Điều này sẽ tối ưu hơn so với việc sử dụng các biến  
  riêng lẽ, để lưu trữ trạng thái các tính năng tránh gây lãng phí vùng nhớ và chậm quá trình xử lý  
  của CPU.  
# 2. Ứng dụng của bitmask và các toán tử logic, phép dịch bit  
## 2.1 Phép dịch bit  
  Được sử dụng khi ta muốn đọc/ghi/xoá/kiểm tra 1 bit  
  + Dịch trái << : khi ta cần đẩy các bit từ phải sang trái    
![image](https://github.com/user-attachments/assets/362ee055-e494-428d-a98d-eab40de8eab9)    

  + Dịch phải: khi ta cần dịch bit từ trái sang phải    
![image](https://github.com/user-attachments/assets/db93c385-7682-411d-8e92-261ad609acfa)    

## 2.2 Sử dụng phép AND và NOT  
  ![image](https://github.com/user-attachments/assets/b5f18aa8-ac9a-4ceb-89db-09ae444627a7)      
  a, Đọc giá trị của 1 bit  
    - Ta sử dụng cơ chế bitmask và thực hiện phép AND tại vị trí mà ta muốn đọc trạng thía bit và  
    phép dịch trái << như đoạn code  
    - Nếu kết quả là 1 số khác 0 thì ta sẽ trả giá trị 1 và  ngược lại.    
        ![image](https://github.com/user-attachments/assets/672b5f65-c41a-4968-9994-923e64dc62b1)    
        ![image](https://github.com/user-attachments/assets/5c29bb1b-8fa1-425a-9d67-4bb2a6f2012c)      
        bitmask = 1 (1 << position) tạo ra 1 bitmask với bit ở vị trí position là 1, còn lại là 0  
        num & (1 << position) sẽ giữ lại bit ở vị trí cần kiểm tra  
        Nếu kết quả khác 0 -> bit đó là 1, ngược lại là 0.  
        Nhị phân của 12 là 0000110  
        Bit thứ 2 là 1 → vì 00001100, bit số 2 (đếm từ 0) là 1.  

  b, lấy giá trị của 1 bit  
    - Ta sẽ thực hiện dịch >> với số lần tương ướng với vị trí bit mà ta muốn lấy ra mà AND với bit mask  
      ![image](https://github.com/user-attachments/assets/3d92f809-b337-42b5-8dec-f9507996f4d1)   
      🧠 Từng bước hoạt động:  
     *  num >> pos  
      Dịch phải num đi pos bit, đưa bit cần đọc về vị trí thấp nhất (LSB – bit 0).  
      Ví dụ:   num = 0b00001100, pos = 2 → num >> 2 = 0b00000011    
     *  & bitmask (bitmask = 1)    
      Lấy bit thấp nhất sau khi dịch phải.    
      Nếu bit đó là 1 → trả về 1, nếu là 0 → trả về 0. 
    
  - ví dụ:    
        get_bit(12, 2)  
        12 = 00001100  
        Dịch phải 2 bit: 00000011  
        00000011 & 00000001 = 00000001 → kết quả: 1  

    


    

