let price = [250, 300, 350, 400, 450, 500];
for (let i = 0; i < price.length; i++) {
   let discount = 0.1 * price[i];
   let discountedPrice = price[i] - discount;
   console.log('the discount price is', discountedPrice);

}