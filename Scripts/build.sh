buildSystem=""
buildType=$2
project=""

#########################################
#				  Clean 				#
#########################################
function Clean()
{
	rm ./build/* -rf
}

#########################################
#				Build lib				#
#########################################
function Lib()
{
	project="libsq.a"
	rm ./build/${buildSystem}/${project}
	cmake ./Engine/ -B ./build/${buildSystem} -DCMAKE_BUILD_TYPE=${buildType} -G "Ninja"
	ninja -C ./build/${buildSystem}
}

#########################################
#				Build SQ				#
#########################################
function SQ()
{
	project="Sandbox"
	rm ./build/${buildSystem}/Sandbox/Sandbox
	cmake -B ./build/${buildSystem} -DCMAKE_BUILD_TYPE=${buildType} -G "Ninja"
	ninja -C ./build/${buildSystem}
}

function Run()
{
	if [[ -f "./build/${buildSystem}/Sandbox/Sandbox" ]]; then
			xfce4-terminal -T "${project}" -e "/usr/bin/cb_console_runner ./build/${buildSystem}/Sandbox/Sandbox" --show-borders --hide-menubar --hide-toolbar  --geometry=50x15+5+10&
	fi
}

function perftool()
{
	Run
	sleep 5
	echo "Starting performance testing tools..."
	perf record -o /home/rahul/Development/Projects/SQ/perf.data --call-graph dwarf --aio -z --sample-cpu --pid $(pidof Sandbox)
	hotspot /home/rahul/Development/Projects/SQ/perf.data
}

if [[ $1 == "Clean" ]]; then
	Clean
elif [[ $1 == "lib" ]]; then
	buildSystem="lib"
	Lib
	Run
elif [[ $1 == "SQ" ]]; then
	buildSystem="SQ"
	SQ
	Run
elif [[ $1 == "Perf" ]]; then
	buildSystem="SQ"
	SQ
	perftool
fi