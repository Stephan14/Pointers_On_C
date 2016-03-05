struct Full_Sales
{//全额销售

  float sales_tax;
  float licensing_fee;
};

struct Lease_Sales
{//租赁销售
  float down_payment;
  float security_deposit;
  float monthly_payment;
  int lease_term;
};

struct Loan_Sales
{
  float sales_tax;
  float licensing_fee;
  float doun_payment;
  int loan_duration;
  float interest_rate;
  float monthly_payment;
  char name_of_bank[21];
};
struct Sales_Record
{
  char customer_name[21];
  char customer_address[41];
  char model[21];
  float suggested_retail_prise;
  float actual_selling_price;
  enum{ PURE_CASH, CASH_LOAN, LEASE } type;
  union
  {
    struct Full_Sales* f_sales;
    struct Lease_Sales* l_sales;
    struct Sales_Record* s_sales;
  }record;
};
