Tác giả: NGUYỄN VĂN SƠN
Email: vanson.ltrinh@gmail.com

Chương trình được viết trên IDE: Microsoft Visual Studio Community 2019

Mục đích chương trình: 	
	Công ty X là một công ty về gia công và sản xuất phần mềm trên xe ô tô. 
	Yêu cầu viết một chương trình cài đặt và quản lý cơ sở dữ liệu các thông số của xe ô tô trước khi xuất xưởng để bán.
	Chương trình sẽ bao gồm các chức năng cơ bản như sau:
	1. Nhập thông tin cài đặt của các chức năng: Display, Sound, General
	2. Xuất thông tin cài đặt cho các chức năng: Display, Sound, General
	3. Xuất thông tin cho toàn bộ các cài đặt.
	4. khi xuất thông tin: được sắp xếp theo mã số cá nhân hoặc tên chủ xe dựa theo lựa chọn của người dùng  

Mô tả chung về chương trình:
	- Chương trình sẽ cài đặt 1 vài thông số trên 3 chức năng Display, Sound, General. Cụ thể như sau
  	+ Display: light level, screen light level, taplo light level.
 	+ Sound: Media volume level, Call volume level, Navigation volume level, Notification volume level.
  	+ General: Cài đặt timezone và cài đặt ngôn ngữ.
	- Một chiếc xe sẽ có đầy đủ cài đặt của cả Display, Sound, General và các thông tin chung cần quản lý là 
	Tên xe, mã số cá nhân, email người sử dụng(Định dạng email là emai@abc.xyz), ODO, thông tin km cần đến để bảo dưỡng xe.
	- Dữ liệu timezone (từ file timezones.txt), language (từ file languages.txt) phải sắp xếp theo Anphabet, hiển thị
	ra màn hình và đưa lựa chọn cho người sử dụng 
	- với chức năng General. Nếu không tìm thấy thì lưu dữ liệu mặc định ra file tương ứng.
	- Dữ liệu các xe sẽ được lưu trữ và cập nhật lại