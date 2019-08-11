class City{
public:
  vector<City*> connectedCities;
  int index;

  City(int index_);
};

class Path{
public:
  City* currentCity;
  bool isHuman;

  Path(City* cC,bool isHuman_);
}

Path::Path(City* cC,bool isHuman_){
  currentCity = cC;
  isHuman = isHuman_;
}

City::City(int index_){
  index = index_;
}

vector<City*> cities;

bool isPossable(int S, int E, int L, int R){
  auto currentPaths = vector<Path>{Path(cities[S],true)};
  while (find_if(currentPaths.begin(),currentPaths.end(),[E](Path path){return path.index == E;}) == currentPaths.end() && currentPaths.size() > 0){
    vector<Path> currentPaths_copy;
    copy(currentPaths.begin(),currentPaths.end(),currentPaths_copy.back_inserter());
    currentPaths.clear();
    for(auto city : currentPaths_copy){
      for(auto next_city: city.currentCity->connectedCities){
        if(next_city.index < L && city.isHuman){
          currentPaths.push_back(Path(next_city,city.isHuman));
        }
        else if(next_city.index > R && !city.isHuman){
          currentPaths.push_back(Path(next_city,city.isHuman));
        }
        else if(next_city.index <= R && next_city.index >= L){
          if(city.isHuman){
            currentPaths.push_back(Path(next_city,!city.isHuman));
          }
          currentPaths.push_back(Path(next_city,city.isHuman));
        }
      }
    }
    currentPaths_copy.clear();
  }
  return find_if(currentPaths.begin(),currentPaths.end(),[E](Path path){return path.index == E;});
}

int* check_validity(int N, int* X, int* Y, int* S, int* E, int* L, int* R){
  int M = sizeof(X)/sizeof(X[0]);
  int Q = sizeof(S)/sizeof(S[0]);

  for(int n = 0; n < N; n++){
    cities.push_back(new City(n));
  }
  for(int i = 0; i < M; i++){
    cities[X[i]]->cities.push_back(cities[Y[i]]);
  }
  int* output = malloc(sizeof(int)*Q);
  for(int i = 0; i < Q; i++){
    output[i] = isPossable(S[i],E[i],L[i],R[i]);
  }
  return output;
}
