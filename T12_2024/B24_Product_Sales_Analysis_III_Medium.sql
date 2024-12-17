/* Write your PL/SQL query statement below */
select product_id, first_year , quantity , price
from(
select a.product_id, year first_year, quantity, price, rank() over(partition by a.product_id order by year) rnk
from sales a
)
where rnk = 1
