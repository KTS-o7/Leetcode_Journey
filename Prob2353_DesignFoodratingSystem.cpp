class FoodRatings {
  
    unordered_map<string,int>foodRating;
    unordered_map<string,string>foodCuisine;
    unordered_map<string,set<pair<int,string>>>cuisineFood;
public:
 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
         auto fastio=[](){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return nullptr;
    };
        for(int i=0;i<foods.size();i++)
            {
                foodRating[foods[i]]=ratings[i];
                foodCuisine[foods[i]]=cuisines[i];
                cuisineFood[cuisines[i]].insert({-ratings[i],foods[i]});
            }
    }
    
    void changeRating(string food, int newRating) {
         auto fastio=[](){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return nullptr;
    };
        auto cuisineName=foodCuisine[food];
        auto oldElement = cuisineFood[cuisineName].find({-foodRating[food],food});
        cuisineFood[cuisineName].erase(oldElement);
        foodRating[food]=newRating;
        cuisineFood[cuisineName].insert({-newRating,food});
        
    }
    
    string highestRated(string cuisine) {
         auto fastio=[](){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return nullptr;
    };
        
        auto highestRating = *cuisineFood[cuisine].begin();
        return highestRating.second;
    }
};
/*foodRating: an unordered map that maps each food to its rating.
foodCuisine: an unordered map that maps each food to its cuisine.
cuisineFood: an unordered map that maps each cuisine to a set of pairs, where each pair consists of the negative rating and the food name. The negative rating is used to sort the foods in descending order of their ratings.
The class has a constructor and two member functions: changeRating and highestRated.

The constructor takes three parameters: a vector of foods, a vector of cuisines, and a vector of ratings. It initializes the three data structures using these parameters. For each food, it sets the rating in foodRating, the cuisine in foodCuisine, and inserts a pair of the negative rating and the food name into the set for the corresponding cuisine in cuisineFood.

The changeRating function takes a food name and a new rating as parameters. It updates the rating for the given food in foodRating and cuisineFood. To update the rating in cuisineFood, it first finds and removes the old element from the set for the corresponding cuisine, and then inserts a new element with the new rating.

The highestRated function takes a cuisine name as a parameter and returns the name of the highest-rated food for the given cuisine. Since the foods in each set in cuisineFood are sorted in descending order of their ratings, the highest-rated food is the first element in the set.

The fastio lambda function used in the constructor and the member functions is a common technique in competitive programming to speed up input/output operations. It disables the synchronization between the C and C++ standard streams, and unties cin from cout, which can significantly improve performance for programs that perform a large number of these operations.*/

//time complexity: O(nlogn) for the constructor, O(logn) for changeRating, and O(1) for highestRated.
//space complexity: O(n) for the constructor, O(1) for changeRating, and O(1) for highestRated.
