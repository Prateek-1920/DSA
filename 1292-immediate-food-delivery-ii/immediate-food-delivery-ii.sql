# Write your MySQL query statement below
with first_orders as (
    select customer_id, order_date ,customer_pref_delivery_date as pref_date
    from delivery
    where(customer_id ,order_date) in
    (
        select customer_id  , min(order_date)
        from Delivery  
        group by customer_id 
    ) 
)

,counts as (
    select count(*) as total,
    sum(order_date = pref_date) as imm
    from first_orders
)

select round((imm*100/total),2) as immediate_percentage  from counts;





