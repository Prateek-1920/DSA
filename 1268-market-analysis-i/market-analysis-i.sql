# Write your MySQL query statement below
with temp as (
select buyer_id, count(buyer_id) as count from orders where year(order_date) = 2019 group by buyer_id 
)

select u.user_id as buyer_id, u.join_date, ifnull(t.count,0) as orders_in_2019 
from users u left join temp t on u.user_id = t.buyer_id; 