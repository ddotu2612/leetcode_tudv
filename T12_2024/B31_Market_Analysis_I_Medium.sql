/* Write your PL/SQL query statement below */
select u.user_id buyer_id, to_char(u.join_date, 'yyyy-MM-dd') join_date, count(order_id) orders_in_2019
from (select * from orders where  to_char(order_date, 'yyyy') ='2019') o
right join users u on o.buyer_id = u.user_id
group by u.user_id, u.join_date
