# Write your MySQL query statement below
select round((count(case when d.order_date=d.customer_pref_delivery_date then 1 end)/count(*))*100, 2)immediate_percentage from delivery d
# subquery to look at first order only
where d.order_date=(
    select
    min(order_date) from delivery 
    where customer_id=d.customer_id
)
