#ifndef BACKYARDBRAINS_ANALYSISPLOTS_H
#define BACKYARDBRAINS_ANALYSISPLOTS_H

#include "widgets/Widget.h"
#include "AnalysisView.h"

namespace BackyardBrains {

namespace Widgets {
	class Plot;
	class TabBar;
}
class RecordingManager;

class AnalysisPlots : public Widgets::Widget {
public:
	AnalysisPlots(const std::vector<SpikeTrain> &spikeTrains, const RecordingManager &manager, Widget *parent = NULL);
	void setActive(bool active);
	bool active() const;

	void update();
	void updateTrain(int idx);
	void setTarget(int target);
private:
	const RecordingManager &_manager;
	bool _active;
	const std::vector<SpikeTrain> &_spikeTrains;

	int _target;

	Widgets::TabBar *_tabs;
	std::vector<Widgets::Plot *> _plots;

	void setAvgWaveformData(int i);
	void setAutocorrData(int i);
	void setCrosscorrData(int i);
	void setISIData(int i);

	void tabChanged(int ntab);
	void setData(int idx, int tab);

	void paintEvent();
};

}

#endif