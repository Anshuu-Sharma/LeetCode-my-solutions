class StockPrice
{
public:
    void update(int timestamp, int price)
    {
        records[timestamp] = price;
        current_time = std::max(current_time, timestamp);
        maxPrices.emplace(price, timestamp);
        minPrices.emplace(price, timestamp);
    }

    int current()
    {
        return records.at(current_time);
    }

    int maximum()
    {
        if (maxPrices.empty())
            return -1;
        while (records.at(maxPrices.top().second) != maxPrices.top().first)
            maxPrices.pop();
        return maxPrices.top().first;
    }

    int minimum()
    {
        if (minPrices.empty())
            return -1;
        while (records.at(minPrices.top().second) != minPrices.top().first)
            minPrices.pop();
        return minPrices.top().first;
    }

private:
    int current_time = 0;

    /*
        pair<int, int> record:
        {
            int timestamp;
            int price;
        }
    */
    unordered_map<int, int> records;

    /*
        pair<int, int> entry:
        {
            int price;
            int timestamp;
        }
    */

    priority_queue<pair<int, int>> maxPrices;
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> minPrices;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */