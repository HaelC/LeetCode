class Vector2D {
private:
    vector<int>::iterator it1d;
    vector<vector<int>>::iterator it2d;
    vector<vector<int>>::iterator end;
    
    void movePointers() {
        while (it2d != end && it1d == it2d->end()) {
            it2d++;
            if (it2d == end) {
                return;
            }
            it1d = it2d->begin();
        }
    }
    
public:
    Vector2D(vector<vector<int>>& v) {
        it2d = v.begin();
        end = v.end();
        while (it2d != end && it2d->size() == 0) {
            it2d++;
        }
        if (it2d == end) {
            return;
        }
        it1d = it2d->begin();
    }
    
    int next() {
        int result = *it1d++;
        movePointers();
        return result;
    }
    
    bool hasNext() {
        return it2d != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */