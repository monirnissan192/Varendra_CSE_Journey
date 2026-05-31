create database Presentation;
use Presentation;

create table users(
userID int not null primary key,
fullName varchar(50),
Email varchar(50),
password varchar(50),
phoneNumber varchar(50),
Gender varchar(50),
created_at datetime,
Date_of_Birth date
);

create table sellers(
sellerID int not null primary key,
storeName varchar(50),
Email varchar(50),
phoneNumber varchar(50),
rating float,
joinDate date,
status varchar(10) NOT NULL Check (status IN ('Active', 'Off'))
);

create table Product_catagory(
catagoryID int not null primary key,
catagoryName varchar(50)
);


create table Products(
productID int not null primary key,
sellerID int,
catagoryID int,
productName varchar(50),
Description text,
price float,
rating float,
sold_product int,
stock_quantity int,
foreign key (sellerID) references Sellers(sellerID),
foreign key (catagoryID) references Product_catagory(catagoryID)
);

create table shippingAddress(
shippingAddressID int not null primary key,
userID int,
fullName varchar(50),
phoneNumber varchar(50),
addressLine varchar(50),
city varchar(50),
postalCode varchar(50),
foreign key (userID) references users(userID)
);

create table productReviews(
reviewID int not null primary key,
userID int,
productID int,
rating float,
comment text,
created_at datetime,
foreign key (userID) references users(userID),
foreign key (productID) references Products(productID)
);
 
create table Addtocart(
AddtocartID int not null primary key,
productID int,
quantity int,
unitPrice float,
total_price float,
foreign key (productID) references Products(productID),
);

create table coupons(
couponID int not null primary key,
code varchar(50),
discount_percent float,
max_user int,
expiry_date date,
active tinyint
);

create table inventory_logs(
log_ID int not null primary key,
productID int,
quantityc_changed int,
updated_at datetime,
foreign key (productID) references products(productID)
);

create table wishlist(
wishlist_Id int not null Primary Key,
user_Id int,
foreign Key(User_Id)references users(userId),
product_Id int,
foreign Key(product_Id) references products(ProductId),
Added_At Date
);

create table analytics(
analytics_Id int not null Primary Key,
user_Id int,
foreign Key(user_Id)references users(userId),
productId int,
foreign Key (productId) references Products(productId),
timeStamp date,
);


create table orders(
orderID int not null primary key,
userID int,
AddtocartID int,
shippingAddressID int,
total_amount float,
order_status varchar(50),
orderTime datetime,
foreign key (userID) references users(userID),
foreign key (AddtocartID) references Addtocart(AddtocartID),
foreign key (shippingAddressID) references shippingAddress(shippingAddressID)
);

create table payments(
paymentID int not null primary key,
orderID int,
couponID int,
method varchar(50),
amount float,
status varchar(50),
transactionID int,
payed_at datetime,
foreign key (couponID) references coupons(couponID),
foreign key (orderID) references orders(orderID),
);

create table shipments(
shipmentID int not null primary key,
orderID int,
trackingNum varchar(50),
courierName varchar(50),
shippedDate datetime,
delivaryDate datetime,
status varchar(50),
foreign key (orderID) references orders(orderID),
);

create table returnItem(
returnID int not null primary key,
userID int,
sellerID int,
productID int,
returnDate date,
reason text,
foreign key (userID) references users(userID),
foreign key (sellerID) references Sellers(sellerID),
foreign Key(productID) references Products(productID)
);


