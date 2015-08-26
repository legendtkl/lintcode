/*
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *		   this->start = start;
 *		   this->end = end;
 *     }
 * }
 */

class Solution {
public:
	static bool cmp(Interval item1, Interval item2) {
		return item1.start < item2.start;
	}

	vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> ret;
		int pos=0, n=intervals.size();

		while(pos<n) {
			int i=pos+1;
			for(; i<n&&intervals[pos].end>=intervals[i].start; ++i)
				intervals[pos].end = max(intervals[pos].end, intervals[i].end);
			ret.push_back(intervals[pos]);
			pos = i;
		}
		return ret;
	}
};
