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

********** chốt: Việc dử dụng phép dịch bít sang trái or phải kêt hợp với toàn tử AND dùng để đọc giá trị của 1 bit

   c, Reset giá trị của bit
    - Đầu tiên ta sẽ sử dụng bitmask và dịch sang trái << đến vị trí của bit mà ta muốn reset
    - Sau đó ta sẽ dử dụng phép NOT để đảo trạng thái các bit
    - Cuối cùng là thực hiện phép AND với kết quả trên ta sẽ reset được bit ở vị trí mà ta muốn, trong khi các giá trị của bit 
    khác được giữ nguyên.
        ![image](https://github.com/user-attachments/assets/e0b916fc-c14d-49af-8e2b-a6447ac63e82)    

## 2.3 Sử dụng phép OR

  ![image](https://github.com/user-attachments/assets/2750dcb0-b05c-44b8-a9a7-db0bfded0c0f)  

  a, set giá trị của 1 bit
  -  Ta sẽ sử dụng bitmask và dịch trái đến vị trí muốn set giá trị lên 1 và thực hiện phép OR
        ![image](https://github.com/user-attachments/assets/7f58dcb9-37b7-4f4c-b0d6-5be7527deb41)
## 2.4 Sử dụng phép XOR
![image](https://github.com/user-attachments/assets/62690482-374f-43c3-9435-96e153e3ad8a)    

  Ta sẽ sử dụng phép toán này để đảo trạng thái của 1 bit
    - Ví dụ: Tìm sự khác biệt giữa số bit 1 trong 2 số.
     ![image](https://github.com/user-attachments/assets/357b5ee1-dbcb-4078-a7cf-6eefc5857a85)



  


    

    


    

