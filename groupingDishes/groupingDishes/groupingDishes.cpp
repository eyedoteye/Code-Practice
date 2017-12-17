#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class ingredient_grouped_dishes
{
  std::unordered_map<
    std::string,
    std::vector<std::string>> dishes;

public:
  void AddDishToIngredientGroup(std::string Ingredient, std::string Dish);
  std::vector<std::vector<std::string>> GetVectorForm();
  void Print();
};

void
ingredient_grouped_dishes::AddDishToIngredientGroup(
  std::string ingredient, std::string dish
)
{
  this->dishes[ingredient].push_back(dish);
}

std::vector<std::vector<std::string>>
ingredient_grouped_dishes::GetVectorForm()
{
  std::vector<std::vector<std::string>> dishesVectorForm;

  for(auto groupedDish : this->dishes)
  {
    if(groupedDish.second.size() > 1)
    {
      std::vector<std::string> rowVector;

      rowVector.push_back(groupedDish.first);
      for(auto dish : groupedDish.second)
      {
        rowVector.push_back(dish);
      }

      std::sort(rowVector.begin() + 1, rowVector.end());
      dishesVectorForm.push_back(rowVector);
    }
  }

  // When a vector is sorted,
  // it compares the first element in each vector.
  // It will only check the second element if the first elements are equal.
  // This is why no special comparator is needed.
  std::sort(dishesVectorForm.begin(), dishesVectorForm.end());

  return dishesVectorForm;
}

void
ingredient_grouped_dishes::Print()
{
  for(auto ingredientDishesPair : this->dishes)
  {
    if(ingredientDishesPair.second.size() > 1)
    {
      std::cout << ingredientDishesPair.first << ":";
      for(auto dish : ingredientDishesPair.second)
      {
        std::cout << " " << dish;
      }
      std::cout << std::endl;
    }
  }
}


// -- Primary Function

std::vector<std::vector<std::string>> GroupingDishes(std::vector<std::vector<std::string>> dishes)
{
  ingredient_grouped_dishes IngredientGroupedDishes;

  for(auto dish : dishes)
  {
    std::string dishName = dish[0];
    //std::cout << dish[0] << ":";
    for(std::vector<std::string>::iterator ingredient = dish.begin() + 1;
        ingredient != dish.end();
        ++ingredient)
    {
      IngredientGroupedDishes.AddDishToIngredientGroup(*ingredient, dishName);
    }
    //std::cout << endl;
  }

  //printGroupedDishes(groupedDishes);

  return IngredientGroupedDishes.GetVectorForm();
}

// ------- Testing:

void PrintVectorOfVectorOfStrings(const std::vector<std::vector<std::string>> &VectorOfVectorOfStrings)
{
  for(auto Row : VectorOfVectorOfStrings)
  {
    for(auto Col : Row)
    {
      std::cout << Col << " ";
    }
    std::cout << std::endl;
  }
}

void FillDishes(std::vector<std::vector<std::string>> &dishes)
{
  std::vector<std::string> dish;
  dish.push_back("Salad");
  dish.push_back("Tomato");
  dish.push_back("Cucumber");
  dish.push_back("Salad");
  dish.push_back("Sauce");
  dishes.push_back(dish);

  dish.clear();
  dish.push_back("Pizza");
  dish.push_back("Tomato");
  dish.push_back("Sausage");
  dish.push_back("Sauce");
  dish.push_back("Dough");
  dishes.push_back(dish);

  dish.clear();
  dish.push_back("Quesadilla");
  dish.push_back("Chicken");
  dish.push_back("Cheese");
  dish.push_back("Sauce");
  dishes.push_back(dish);

  dish.clear();
  dish.push_back("Sandwich");
  dish.push_back("Salad");
  dish.push_back("Bread");
  dish.push_back("Tomato");
  dish.push_back("Cheese");
  dishes.push_back(dish);
}

int main()
{
  std::vector<std::vector<std::string>> dishes;
  FillDishes(dishes);

  std::cout << "Before Grouping:" << std::endl;
  PrintVectorOfVectorOfStrings(dishes);

  std::cout << std::endl;

  std::cout << "After Grouping:" << std::endl;
  std::vector<std::vector<std::string>> groupedDishes;
  groupedDishes = GroupingDishes(dishes);
  PrintVectorOfVectorOfStrings(groupedDishes);

  return 0;
}