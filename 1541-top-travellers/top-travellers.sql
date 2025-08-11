# Write your MySQL query statement below
select u.name ,
case
when
u.id in (select user_id from rides) then sum(r.distance)
else 0
end as travelled_distance  
from users u left join rides r on 
u.id = r.user_id
group by r.user_id
order by travelled_distance desc, u.name;