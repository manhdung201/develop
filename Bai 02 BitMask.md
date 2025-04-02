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
  + Dịch phải:
