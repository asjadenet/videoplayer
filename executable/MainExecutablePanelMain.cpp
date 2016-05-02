//<boost/asio/ip/tcp.hpp> must be first to prevent "WinSock.h has already been included" error
#include <boost/asio/ip/tcp.hpp>
#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <fstream>
#include <get_file_names_from_path.h>
#include <http_get_video_files.h>
#include <boost/filesystem/path.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <HttpGet.h>
#include <get_play_request_json.h>
#include <Config.h>
#include <cmake_conf.h>
#include <get_stop_request_json.h>
#include <get_pause_request_json.h>
#include <format_time.h>
#include <http_get_player_percentage.h>
#include <parse_json_percentage.h>
#include <get_time_request_json.h>
#include <parse_json_time.h>
#include "MainExecutablePanelMain.h"

MainExecutablePanelMain::MainExecutablePanelMain( wxWindow* parent )
:
PanelMain( parent )
{
    auto config_dir = ::wxStandardPaths::Get().GetUserConfigDir();
        Config::read(config_dir.ToStdString(), (std::string) APP_NAME);
        auto videofiles_full_path = http_get_video_files(Config::setting["videoDir"], Config::httpConf);
        if (videofiles_full_path.size() > 0) {
            boost::filesystem::path p(videofiles_full_path[0]);
            video_files_path = p.parent_path();
            auto videofiles = get_file_names_from_path(videofiles_full_path);
            for (auto file: videofiles) {
                m_listBox2->Append(file);
                timer_enabled = true;
            }
        }
}

void MainExecutablePanelMain::open_video() const {
    auto index = m_listBox2->GetSelection();
    if(index<0)
        return;
    wxString selectedValue = m_listBox2->GetString((unsigned int) index);

    boost::filesystem::path filename(selectedValue);
    auto fullpath = video_files_path / filename;
    string fullpath_str = fullpath.string();
    boost::algorithm::replace_all(fullpath_str, "\\", "/");

    auto request_str = get_play_request_json(fullpath_str);
    HttpGet::execute(request_str, Config::httpConf);
}

void MainExecutablePanelMain::set_percentage(double value) {
    m_slider1->SetValue((int) std::round(value));
}



void MainExecutablePanelMain::btnStopClick(wxCommandEvent &event) {
    m_toggleBtnPlayPause->SetValue(false);
    m_toggleBtnPlayPause->SetLabelText("|> vaata");
    auto request_str = get_stop_request_json();
    HttpGet::execute(request_str, Config::httpConf);
}

void MainExecutablePanelMain::set_time_label(wxString timeLabel) {
    m_staticTextTime->SetLabelText(timeLabel);
}

void MainExecutablePanelMain::toggleBtnPlayPauseClick(wxCommandEvent &event) {
    auto index = m_listBox2->GetSelection();
    if(index<0) {
        m_toggleBtnPlayPause->SetValue(false);
        return;
    }
    if(m_toggleBtnPlayPause->GetValue()){
        m_toggleBtnPlayPause->SetLabelText("|| peata");
        if(time_zero())
        {
            open_video();
        }
        else {
            pause_video();
        }
    }
    else {
        m_toggleBtnPlayPause->SetLabelText("|> vaata");
        pause_video();
    }
}

void MainExecutablePanelMain::pause_video() const {
    auto request_str = get_pause_request_json();
    HttpGet::execute(request_str, Config::httpConf);
}

void MainExecutablePanelMain::timer_tick() {
    if(!timer_enabled)
        return;
    auto json = http_get_player_percentage(Config::httpConf);
//    wxMessageBox(json);
    auto percentage = parse_json_percentage(json);
    set_percentage(percentage);

    auto request_url = get_time_request_json();

    auto result = HttpGet::execute(request_url, Config::httpConf);
//    std::cout << result.body << std::endl;
    auto times = parse_json_time(result.body);
    time = times["time"];
    totaltime = times["totaltime"];
//    std::cout << time.hours << ":"  << time.minutes << ":" << time.seconds << std::endl;

    wxString timeLabelText = format_time(time) + "/" + format_time(totaltime);
    set_time_label(timeLabelText);
}

bool MainExecutablePanelMain::time_zero() {
    return totaltime.hours == 0 && totaltime.milliseconds == 0 && totaltime.minutes == 0 && totaltime.seconds == 0 && time.milliseconds == 0 && time.seconds == 0 && time.minutes == 0 && time.hours == 0;
}

void MainExecutablePanelMain::btnExitClick(wxCommandEvent &event) {
    m_parent->Close(true);
}
















