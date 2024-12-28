-- /* Write your PL/SQL query statement below */
-- select a.product_id, case when change_date <= to_date('2019-08-16', 'yyyy-MM-dd') then a.new_price else 10 end price
-- from (
-- select a.*, row_number() over(partition by product_id order by before, abs(change_date - to_date('2019-08-16', 'yyyy-MM-dd'))) rnk
-- from 
-- (select a.*, case when change_date <= to_date('2019-08-16', 'yyyy-MM-dd') then 0 else 1 end before from products a) a
-- ) a
-- where rnk = 1
/* Write your PL/SQL query statement below */
select product_id, FIRST_VALUE (new_price)over (partition by product_id order by change_date desc) as price from products where change_date <= '2019-08-16' 
union 
select  product_id, 10 as price from products 
where product_id not in (select product_id from products where change_date <='2019-08-16')
