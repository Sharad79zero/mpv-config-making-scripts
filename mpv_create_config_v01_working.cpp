#include <fstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>

using namespace std;

void make_mpv_conf_file(string path_upto_username){

    ofstream file_writer( path_upto_username+"AppData\\Roaming\\mpv\\mpv.conf" ); // file_writer is just a named object which can write things
    if ( ! file_writer.is_open() ){ // checking if the file is opened 
        cout << "Could not open file!" << '\n';
    }

    // raw string syntax is rawstring = R"(ghuiyanlassan)" 
    // raw string keep the \n,\t and other thing as same it is without conveying any meaning

    file_writer<<R"(# read notes.txt it may be useful. then read a very little mpv manual i would suggest subtitles part only.
# cmd = "C:\Program Files (x86)\mpv-x86_64-20220109-git-777628e\mpv.exe" --no-config "location of file"
#						OR
# if you added mpv to path you dont need to specify mpv.exe at start : 
# cmd = mpv --no-config -sub-font="Gandhi Sans" -sub-font-size=48 -sub-bold=yes -sub-border-color=0.0/0.0/0.0/1.0 -sub-border-size=2.2 -sub-shadow-color=0.0/0.0/0.0/0.6 -sub-shadow-offset=1.2 -sub-margin-x=90 -sub-margin-y=38 -sub-fix-timing=yes "D:\Movies\UN-WATCHED\Prisoners.2013.720p.Brrip.x265.HEVC.10bit.PoOlLa.mkv" 

###################################
       #General settings#
###################################

#profile=gpu-hq                                # applies many recommended options to this config(ex: its sets deband to yes automatically) important note in the notes.txt if you have a shitty graphics card/gpu.
ontop=no                                      # whether mpv stays on top of all opened applications or not (ex:default = no)
# deband=yes                                  # always yes for anime(it is related to displaying different shades of same colour) 
blend-subtitles=no                            # if value is set to "video" then if anime/movie is blurry then subtitles also will be blurry
force-seekable=yes
keep-open=yes                                 # using autoload script/extension it will pause the video at last frame of last episode/ last movie part.
write-filename-in-watch-later-config          # self explanatory
use-filedir-conf                              # enables directory-specific configuration first mpv.conf(main) is loaded then this
#video-aspect-override=16:9                   # seriously dont do this.                                                   

####################################################
      #audio,subtitle language preferance order#
####################################################

alang=ko,kor,korean,ja,jp,jpn,japanese,en,eng,english,hi,hin,hindi
slang=ja,jap,en,eng

#############################
      #subtitle settings#
#############################

############# MY SHITTY SUBS STYLE###################

#sub-auto=fuzzy                                         # auto loads external subs containing media filename
#sub-font='Gandhi Sans'                                 # font used for SRT and overrides
#sub-bold=yes                                           # it is better to use this option than to use "<fontname> Bold" in sub-font=____
#sub-font-size=48                                       # font size used SRT and overrides
#sub-border-color=0.0/0.0/0.0/1.0                       # value of white in r/g/b/a format where a is alpha.read my notes or mpv manual.
#sub-border-size=2.5                                    # 2.4 is just perfect! 
#sub-shadow-color=0.0/0.0/0.0/0.4                       # transparent Black shadow.its must be lightly visible like 0.4 something alpha value its 0.6 for now(koby's)
#sub-shadow-offset=4                                    # how much shadow. 2 value is good alpha value of sub-shadow-color is 0.4 
#sub-margin-x=90                                        # how much away subtitles will be from left/right
#sub-margin-y=38                                        # how much away subtitles will be from top/bottom
#sub-fix-timing=yes                                     # Fixes subtitle timing for gaps smaller than 210ms
#sub-ass-override=no                                    # overrides ass styling, enable only in profiles


###### SUB STYLE OF A GOD IN ANIME COMMUNITY (Mr. KOBY !!!) ######

sub-auto=fuzzy                          # auto loads external subs containing media filename
demuxer-mkv-subtitle-preroll=yes
sub-ass-override=no                     # overrides ass styling, enable only in profiles
sub-font='Gandhi Sans'                  # font used for SRT and overrides
sub-font-size=48                        # font size used SRT and overrides
sub-bold=yes
sub-border-color=0.0/0.0/0.0/1.0
sub-border-size=2.2
sub-shadow-color=0.0/0.0/0.0/0.6
sub-shadow-offset=1.2
sub-margin-x=90
sub-margin-y=38
sub-gauss=1.0                           # Slightly blurs VOB/PGS subtitles to look better
sub-gray=yes                            # Changes yellow PGS subtitles to grey
sub-fix-timing=yes                      # Fixes subtitle timing for gaps smaller than 210ms



# sub-border-size is 2.5 and sub-shadow-offset is 3 MPC-HC style.
# but koby's is more appropriate and eye pleasing (because of pleasant shadow) 

#################  
#    NOTES      #
#################

# [for sub-margin-x] - it's normal fansub practice to do fansubs with 90 to 120 px margins. so I set it to 90 here for srt subs.(-koby)

####################
   #screenshot#
####################

# Output format of screenshots
screenshot-format=jpg

# Same output bitdepth as the video. Set it "no" if you want to save disc space
screenshot-high-bit-depth=no

# Compression of the PNG picture (1-9). Higher value means better compression, but takes more time
screenshot-png-compression=7

# Quality of JPG pictures (0-100). Higher value means better quality
screenshot-jpeg-quality=70

screenshot-tag-colorspace=yes

# where to store the screen shot. here it will be stored in "screens" folder present in the same directory as the video file is in
screenshot-template="%x\Screens\Screenshot-%F-T%wH.%wM.%wS.%wT-F%{estimated-frame-number}"


#########
# Audio #
#########

volume-max=200                                # maximum volume in %, everything above 100 results in amplification
volume=70                                     # default volume, 100 = unchanged
audio-stream-silence                          # fix audio popping on random seek
audio-file-auto=fuzzy                         # auto loads external audio containing media filename
audio-channels=auto-safe                      # Use system preferred channel layout. If there is none, force stereo. 


#############
 # OSD / OSC #
#############

title=${filename} [${time-pos}${!duration==0: / ${duration}}] • ${mpv-version}
autofit-larger=90%x80%
log-file="~~/log.txt"
osc=yes
osd-font='Source Sans Pro'
osd-font-size=30
osd-color='#CCFFFFFF'                        # ARGB format where A is alpha value(transparency)
osd-border-color='#DD322640'                 # ARGB format where A is alpha value(transparency)
osd-bold=yes
osd-margin-y=45
osd-bar=yes                                  # Hides volume bar on screen when turning the volume up/down
osd-bar-align-y=-0.93                        # progress bar alignment (-1 top, 0 centered, 1 bottom)
osd-border-size=1                            # size for osd text and progress bar
osd-bar-h=2                                  # height of osd bar as a fractional percentage of your screen height
osd-bar-w=60                                 # width of " " "
osd-shadow-color=0.0/0.0/0.0/0.6             # transparent shadow.  in r/g/b/a format where a is alpha 
osd-shadow-offset=0.7                        # shadow is a must. but not too much!

#save-position-on-quit)";
    cout<<"successfully created mpv.conf... "<<endl;
}

void make_input_conf_file(string path_upto_username){
    ofstream file_writer( path_upto_username+"AppData\\Roaming\\mpv\\input.conf" ); // file_writer is just a named object which can write things
    if ( ! file_writer.is_open() ){ // checking if the file is opened 
        cout << "Could not open file!" << '\n';
    }

    // raw string syntax is rawstring = R"(ghuiyanlassan)" 
    // raw string keep the \n,\t and other thing as same it is without conveying any meaning

    file_writer<<R"(# Volume
# ======
WHEEL_UP add volume 5
WHEEL_DOWN add volume -5
UP add volume 5
DOWN add volume -5

# Chapter
# =======
# MOUSE_BTN0 add chapter -1  # mine left click is 0
# MOUSE_BTN2 add chapter 1    # mine right click is 2
# MOUSE_BTN1 show-progress  # mine middle button is 1

# Subtitle Track Change
# =====================
s cycle sub

# Audio Track Change
# ==================
a cycle audio

# Audio Downmix Toggle
# ====================
+ cycle-values audio-channels stereo auto-safe

# Screenshot WITH subs
# ====================
S async screenshot

# Cycles mpv staying ontop or not
# ===============================
# T cycle ontop

# Video Debanding Toggle
# ======================
d cycle deband


R cycle_values video-rotate 90 180 270 0)";
    cout<<"successfully created input.conf... "<<endl;
}

void make_notes_txt_file(string path_upto_username){
        ofstream file_writer( path_upto_username+"AppData\\Roaming\\mpv\\notes.txt" ); // file_writer is just a named object which can write things
    if ( ! file_writer.is_open() ){ // checking if the file is opened 
        cout << "Could not open file!" << '\n';
    }

    // raw string syntax is rawstring = R"(ghuiyanlassan)" 
    // raw string keep the \n,\t and other thing as same it is without conveying any meaning
    // here we would have to use a delimiter that we used is x between " and ( beacuse our string contains this : )" 
    file_writer<<R"x(###########
   NOTES
###########
1) mpv.conf file store all the mpv settings. But some settings like "--no-config" can be only applied on command line or terminal. Oh man i miss using linux...

2) input.conf have custom control settings like mouse wheel up = volume increase. Good old VLC style.

3) #optional "lua-settings" is for thumbnail script to work by setting "prefer_mpv=no" and "osc=no" in mpv.conf.

4) inside scripts folder( present in the mpv configuration folder in we place mpv.conf) we place mpv script file(s).

5) #optional we place "censor" folder and main.lua in "scripts" folder in order to censor script to work.

6) in mpv-chapters.js script use rgb values without "#" symbol in front of them.

7) if you want bold subtitles then set sub-font-size between 35-50 and if you dont want bold text set sub-font-size to 50-70.

8) some important colour RRGGBB values:
                                       a)Black-#000000
                                       b)White-#FFFFFF
                                       c)koby's White-#F0F0F0
                                       d)Blue-#0000FF
                                       e)Silver-#C0C0C0
                                       f)Gray-#808080 
   
9) r/g/b/a format of giving colours. it is used to set transparency. where a is alpha or transparency. 1.0 is NOT transparent and 0.0 is  Fully transparent.

10) use Gimp to convert RRGGBB values To points. in the colour picking section in gimp. select [0.. 100] and type the value you want to convert in HTML notation : #C0C0C0 (silver colour) for example.  now the value you will see is  R=75.3 ,B=75.3, C=75.3 . now ignore the decimal point and divide it by 100. we got 0.75/0.75/0.75/0.0

0.8 is good value that Koby and i like to use for OSD and 0.6 for subtitle's shadow.

11) to fix the crash after pasting url into mpv. you need to add youtube-dl to system path .on how to do it. search it on google or this https://techwombat.com/how-to-use-youtube-dl-to-download-videos-from-youtube-on-windows/

12) to download mpv on windows use sourceforge.

13) mpv config path on windows is "C:\Users\username\AppData\Roaming\mpv"

14)syntax for loading with default config:
   "C:\Program Files (x86)\mpv-x86_64-20220109-git-777628e\mpv.exe" --no-config "D:\Anime\Land of the Lustrous 720p\05. Return.mkv"

							OR

   add mpv.exe installation path: go to this pc > properties > advance system settings > environment variables > click on 'path' > 'edit....' > 'new' > paste location of folder where your mpv.exe is present (so cmd can find it easily and you dont have to type full mpv location every time you wanna open some video through command line) > 'ok' !
   Alternate (recommended) syntax after following above line:
                          mpv --no-config --profile=gpu-hq -sub-font="Gandhi Sans" -sub-font-size=48 -sub-bold=yes -sub-border-color=0.0/0.0/0.0/1.0 -sub-border-size=2.2 -sub-shadow-color=0.0/0.0/0.0/0.6 -sub-shadow-offset=1.2 -sub-margin-x=90 -sub-margin-y=38 -sub-fix-timing=yes "D:\Movies\UN-WATCHED\Prisoners.2013.720p.Brrip.x265.HEVC.10bit.PoOlLa.mkv"

15) WARNING : if you dont have a graphics card/gpu DONT ever use "profile=gpu-hq" option. every other mpv guide will tell you to do it but you dont because it will cause the video to stutter and will drop several frames resulting in the bad experience. especially if playing some HEVC-10bit heavy stuff.

16) you can't store the screenshots in the "C:\program files" or "C:\program files (x86)" or in "C:\windows" because you don't have admin rights there(because OS files are there) but after log in using your password you can store it in "C:\Users\username\AppData\Roaming\mpv\screenshots" because you have admin priviliges. you don't require admin rights to store screenshots to other partitions or others hard drives.)x";
    cout<<"successfully created notes.txt..." <<endl;
}

void make_autoload_lua_file(string path_upto_username){
        ofstream file_writer( path_upto_username+"AppData\\Roaming\\mpv\\scripts\\autoload.lua" ); // file_writer is just a named object which can write things
    if ( ! file_writer.is_open() ){ // checking if the file is opened 
        cout << "Could not open file!" << '\n';
    }

    // raw string syntax is rawstring = R"(ghuiyanlassan)" 
    // raw string keep the \n,\t and other thing as same it is without conveying any meaning

    file_writer<<R"x(-- This script automatically loads playlist entries before and after the
-- the currently played file. It does so by scanning the directory a file is
-- located in when starting playback. It sorts the directory entries
-- alphabetically, and adds entries before and after the current file to
-- the internal playlist. (It stops if it would add an already existing
-- playlist entry at the same position - this makes it "stable".)
-- Add at most 5000 * 2 files when starting a file (before + after).

--[[
To configure this script use file autoload.conf in directory script-opts (the "script-opts"
directory must be in the mpv configuration directory, typically ~/.config/mpv/).

Example configuration would be:

disabled=no
images=no
videos=yes
audio=yes
ignore_hidden=yes

--]]

MAXENTRIES = 5000

local msg = require 'mp.msg'
local options = require 'mp.options'
local utils = require 'mp.utils'

o = {
    disabled = false,
    images = true,
    videos = true,
    audio = true,
    ignore_hidden = true
}
options.read_options(o)

function Set (t)
    local set = {}
    for _, v in pairs(t) do set[v] = true end
    return set
end

function SetUnion (a,b)
    local res = {}
    for k in pairs(a) do res[k] = true end
    for k in pairs(b) do res[k] = true end
    return res
end

EXTENSIONS_VIDEO = Set {
    'mkv', 'avi', 'mp4', 'ogv', 'webm', 'rmvb', 'flv', 'wmv', 'mpeg', 'mpg', 'm4v', '3gp'
}

EXTENSIONS_AUDIO = Set {
    'mp3', 'wav', 'ogm', 'flac', 'm4a', 'wma', 'ogg', 'opus'
}

EXTENSIONS_IMAGES = Set {
    'jpg', 'jpeg', 'png', 'tif', 'tiff', 'gif', 'webp', 'svg', 'bmp'
}

EXTENSIONS = Set {}
if o.videos then EXTENSIONS = SetUnion(EXTENSIONS, EXTENSIONS_VIDEO) end
if o.audio then EXTENSIONS = SetUnion(EXTENSIONS, EXTENSIONS_AUDIO) end
if o.images then EXTENSIONS = SetUnion(EXTENSIONS, EXTENSIONS_IMAGES) end

function add_files_at(index, files)
    index = index - 1
    local oldcount = mp.get_property_number("playlist-count", 1)
    for i = 1, #files do
        mp.commandv("loadfile", files[i], "append")
        mp.commandv("playlist-move", oldcount + i - 1, index + i - 1)
    end
end

function get_extension(path)
    match = string.match(path, "%.([^%.]+)$" )
    if match == nil then
        return "nomatch"
    else
        return match
    end
end

table.filter = function(t, iter)
    for i = #t, 1, -1 do
        if not iter(t[i]) then
            table.remove(t, i)
        end
    end
end

-- splitbynum and alnumcomp from alphanum.lua (C) Andre Bogus
-- Released under the MIT License
-- http://www.davekoelle.com/files/alphanum.lua

-- split a string into a table of number and string values
function splitbynum(s)
    local result = {}
    for x, y in (s or ""):gmatch("(%d*)(%D*)") do
        if x ~= "" then table.insert(result, tonumber(x)) end
        if y ~= "" then table.insert(result, y) end
    end
    return result
end

function clean_key(k)
    k = (' '..k..' '):gsub("%s+", " "):sub(2, -2):lower()
    return splitbynum(k)
end

-- compare two strings
function alnumcomp(x, y)
    local xt, yt = clean_key(x), clean_key(y)
    for i = 1, math.min(#xt, #yt) do
        local xe, ye = xt[i], yt[i]
        if type(xe) == "string" then ye = tostring(ye)
        elseif type(ye) == "string" then xe = tostring(xe) end
        if xe ~= ye then return xe < ye end
    end
    return #xt < #yt
end

local autoloaded = nil

function find_and_add_entries()
    local path = mp.get_property("path", "")
    local dir, filename = utils.split_path(path)
    msg.trace(("dir: %s, filename: %s"):format(dir, filename))
    if o.disabled then
        msg.verbose("stopping: autoload disabled")
        return
    elseif #dir == 0 then
        msg.verbose("stopping: not a local path")
        return
    end

    local pl_count = mp.get_property_number("playlist-count", 1)
    -- check if this is a manually made playlist
    if (pl_count > 1 and autoloaded == nil) or
       (pl_count == 1 and EXTENSIONS[string.lower(get_extension(filename))] == nil) then
        msg.verbose("stopping: manually made playlist")
        return
    else
        autoloaded = true
    end

    local pl = mp.get_property_native("playlist", {})
    local pl_current = mp.get_property_number("playlist-pos-1", 1)
    msg.trace(("playlist-pos-1: %s, playlist: %s"):format(pl_current,
        utils.to_string(pl)))

    local files = utils.readdir(dir, "files")
    if files == nil then
        msg.verbose("no other files in directory")
        return
    end
    table.filter(files, function (v, k)
        -- The current file could be a hidden file, ignoring it doesn't load other
        -- files from the current directory.
        if (o.ignore_hidden and not (v == filename) and string.match(v, "^%.")) then
            return false
        end
        local ext = get_extension(v)
        if ext == nil then
            return false
        end
        return EXTENSIONS[string.lower(ext)]
    end)
    table.sort(files, alnumcomp)

    if dir == "." then
        dir = ""
    end

    -- Find the current pl entry (dir+"/"+filename) in the sorted dir list
    local current
    for i = 1, #files do
        if files[i] == filename then
            current = i
            break
        end
    end
    if current == nil then
        return
    end
    msg.trace("current file position in files: "..current)

    local append = {[-1] = {}, [1] = {}}
    for direction = -1, 1, 2 do -- 2 iterations, with direction = -1 and +1
        for i = 1, MAXENTRIES do
            local file = files[current + i * direction]
            local pl_e = pl[pl_current + i * direction]
            if file == nil or file[1] == "." then
                break
            end

            local filepath = dir .. file
            if pl_e then
                -- If there's a playlist entry, and it's the same file, stop.
                msg.trace(pl_e.filename.." == "..filepath.." ?")
                if pl_e.filename == filepath then
                    break
                end
            end

            if direction == -1 then
                if pl_current == 1 then -- never add additional entries in the middle
                    msg.info("Prepending " .. file)
                    table.insert(append[-1], 1, filepath)
                end
            else
                msg.info("Adding " .. file)
                table.insert(append[1], filepath)
            end
        end
    end

    add_files_at(pl_current + 1, append[1])
    add_files_at(pl_current, append[-1])
end

mp.register_event("start-file", find_and_add_entries))x";
    cout<<"successfully created autoload.lua... "<<endl;
}

void make_mpv_chapters_js_file(string path_upto_username){
        ofstream file_writer( path_upto_username+"AppData\\Roaming\\mpv\\scripts\\mpv_chapters.js" ); // file_writer is just a named object which can write things
    if ( ! file_writer.is_open() ){ // checking if the file is opened 
        cout << "Could not open file!" << '\n';
    }

    // raw string syntax is rawstring = R"(ghuiyanlassan)" 
    // raw string keep the \n,\t and other thing as same it is without conveying any meaning

    file_writer<<R"x("use strict";

//display chapter on osd and easily switch between chapters by click on title of chapter
mp.register_event("file-loaded", init);
mp.observe_property("chapter", "number", onChapterChange);
mp.observe_property("chapter-list/count", "number", init);
var options = {
	font_size: 40,
	font_color: "FFFFFF",
	border_size: 1.0,
	border_color: "000000",
	font_color_currentChapter: "00ff00",
};
var playinfo = {
	chapters: [], //array
	chaptercount: "", // int
	assinterface: [], //array(deprecated, use single assdraw instead)
	currentChapter: "", //int
    loaded:false,
};
var toggle_switch = false;
var assdraw = mp.create_osd_overlay("ass-events");
var autohidedelay = mp.get_property_number("cursor-autohide");
//function
function init() {
	playinfo.chapters = getChapters();
	playinfo.chaptercount = playinfo.chapters.length;
    if(playinfo.chaptercount == 0){
        return;
    }
	while (playinfo.chaptercount * options.font_size > 1000 / 1.5) {
		options.font_size = options.font_size - 1;
	}
	drawChapterList();
	mp.msg.info("initiated");
    playinfo.loaded = true;
}
function getChapters() {
	var chapterCount = mp.get_property("chapter-list/count");
	if (chapterCount === 0) {
		return ["null"];
	} else {
		var chaptersArray = [];
		for (var index = 0; index < chapterCount; index++) {
			var chapterTitle = mp.get_property_native(
				"chapter-list/" + index + "/title"
			);

			if (chapterTitle != undefined) {
				chaptersArray.push(chapterTitle);
			}
		}
		return chaptersArray;
	}
}

function drawChapterList() {
	var resY = 0;
	var resX = 0;
	var assdrawdata = "";
	function setPos(str, _X, _Y) {
		str = str + "{\\pos(" + _X + ", " + _Y + ")}";
		return str;
	}
	function setborderSize(str) {
		str = str + "{\\bord" + options.border_size + "}";
		return str;
	}
	function setborderColor(str) {
		str = str + "{\\3c&H" + options.border_color + "&}";
		return str;
	}
	function setFontColor(str, index) {
		var _color;
		if (playinfo.currentChapter == index) {
			_color = options.font_color_currentChapter;
		} else {
			_color = options.font_color;
		}
		str = str + "{\\c&H" + _color + "&}";
		return str;
	}
	function setFont(str) {
		str = str + "{\\fs" + options.font_size + "}";
		return str;
	}
	function setEndofmodifiers(str) {
		str = str + "{\\p0}";
		return str;
	}
	function setEndofLine(str) {
		str = str + "\n";
		return str;
	}
	playinfo.chapters.forEach(function (element, index) {
		assdrawdata = setPos(assdrawdata, resX, resY);
		assdrawdata = setborderSize(assdrawdata);
		assdrawdata = setborderColor(assdrawdata);
		assdrawdata = setFontColor(assdrawdata, index);
		assdrawdata = setFont(assdrawdata);
		assdrawdata = setEndofmodifiers(assdrawdata);
		assdrawdata = assdrawdata + element;
		assdrawdata = setEndofLine(assdrawdata);
		resY += options.font_size;
	});
	assdraw.data = assdrawdata
	
}

function toggleOverlay() {
    if(!playinfo.loaded){
        return;
    }
	if (!toggle_switch) {
		drawChapterList();
		assdraw.update();
		mp.set_property("cursor-autohide", "no");
		toggle_switch = !toggle_switch;
	} else {
		assdraw.remove();
		mp.set_property("cursor-autohide", autohidedelay);
		toggle_switch = !toggle_switch;
	}
}

function onChapterChange() {
	playinfo.currentChapter = mp.get_property_native("chapter");
	if (playinfo.currentChapter != undefined) {
		drawChapterList();
	}

	if ((playinfo.currentChapter != undefined) & toggle_switch) {
		assdraw.update();
	}
}
function pos2chapter(x, y, overallscale) {
	var vectical = y / (options.font_size * overallscale);
    if(vectical > playinfo.chaptercount){
        return null;
    }
	var intVectical = Math.floor(vectical);
	var lengthofTitleClicked = playinfo.chapters[intVectical].length;
	var lengthofTitleClicked_px =
		(lengthofTitleClicked * options.font_size) / overallscale;
	if (x < lengthofTitleClicked_px) {
		return intVectical;
	} else {
		return null;
	}
}
function getOverallScale() {
	return mp.get_osd_size().height / 720;
}
function onMBTN_LEFT() {
	//get mouse position
    if(!playinfo.loaded){
        return;
    }
	if (toggle_switch) {
		var overallscale = getOverallScale();
		var pos = mp.get_mouse_pos();
		var chapterClicked = pos2chapter(pos.x, pos.y, overallscale);
		if (chapterClicked != null) {
			mp.set_property_native("chapter", chapterClicked);
		}
	}
}
mp.add_key_binding("TAB", "tab", function () {
	toggleOverlay();
});
mp.add_key_binding("MBTN_LEFT", "mbtn_left", function () {
	onMBTN_LEFT();
});
)x";
    cout<<"successfully created mpv_chapters.js... "<<endl<<endl;
}


string return_path_upto_username(string username){ // defining a function to return the path upto the username only in string datatype. it takes arguement username that will be taken from the user.
    string left_path,right_path,fullpath;
    left_path = "C:\\Users\\" ;
    right_path = "\\";
    fullpath=left_path+username+right_path;
    return fullpath;                               // return value of path will look something like "C:\Users\jhonny_D" or "C:\Users\Koby"  
}




int main(){
    string username, fullpath_after_verifying_if_it_exists,path_upto_username ;
    cout<<"Enter windows username : ";
    cin>>username ;        //  please note that username is not case sensitive in windows
    
    std::filesystem::path filepath = std::string(return_path_upto_username(username));
    bool filepathExists = std::filesystem::is_directory(filepath);  // filepathExists will return true if path really exists
    path_upto_username = return_path_upto_username(username);       // we can't call this function in other functions so we will first store in the string varibale

    if (filepathExists == true){     // don't do anything if the path exists.
        cout<<endl<<"Correct username!"<<endl<<endl;
        fullpath_after_verifying_if_it_exists = return_path_upto_username(username) + "AppData\\Roaming\\mpv\\scripts";

        std::filesystem::create_directories(fullpath_after_verifying_if_it_exists);     // creates "mpv" folder then "scripts" folder inside it.

        make_mpv_conf_file(path_upto_username);         // make the mpv.conf file in the directory after adding "path_to_username" to the leftover path
        make_input_conf_file(path_upto_username);       // make the input.conf file in the directory after adding "path_to_username" to the leftover path
        make_notes_txt_file(path_upto_username);        // make the notes.txt file in the directory after adding "path_to_username" to the leftover path
        make_autoload_lua_file(path_upto_username);     // make the autoload.lua file in the directory after adding "path_to_username" to the leftover path
        make_mpv_chapters_js_file(path_upto_username);  // make the mpv_chapters.js file in the directory after adding "path_to_username" to the leftover path

    }
    else{     // don't do anything if the path don't exists.
        cout<<"Incorrect username please try again or check username from C:\\Users\\username"<<endl<<endl;
    }
    system("pause");  // for a nice "press any key to continue...." and kept it open
    

    return 0;
}