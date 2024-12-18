/* Write your PL/SQL query statement below */
-- select round(sum(is_imediate)*100/count(*), 2) immediate_percentage
-- from(
-- select case when order_date = customer_pref_delivery_date then 1 else 0 end is_imediate
-- , row_number() over (partition by customer_id order by order_date) rnk
-- from delivery a
-- )
-- where rnk = 1

--C2
select round(sum(is_imediate)*100/count(*), 2) immediate_percentage
from(
select customer_id, case when min(order_date) = min(customer_pref_delivery_date) then 1 else 0 end is_imediate
from delivery a 
group by customer_id
)
