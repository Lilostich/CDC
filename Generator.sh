#!/bin/bash


# Types to generate
ALLOWED_TYPES="test
list
run
project
task
all"

# gen full file struct
TYPE="all"

# postfix for files
TEST_POSTFIX=".meta"
LIST_POSTFIX=".meta"
RUN_POSTFIX=".meta"
PROJECT_POSTFIX=".cfg"
TASK_POSTFIX=".json"

# Number of tests, projects, lists, runs
FACTOR=5        # gen factor
TEST_NUM=$((5 * $FACTOR))      # number of tests to gen
LIST_NUM=$((3 * $FACTOR))      # number of lists to gen
PROJECT_NUM=$((2 * $FACTOR))   # number of projects to gen
RUN_NUM=$((2 * $FACTOR))       # number of runs to get
TASK_NUM=$((4 * $FACTOR))      # number of tasks to get

# remove|create|nothing subFS
ACTION="nothing"

# file struct path
CDC_ROOT=/var/lib/CDC
CDC_USER=cdc
    

die(){
    echo "$1" >&2
    exit 1
}


update_vars(){
    CDC_LOGIN=$CDC_ROOT/Login.cfg
    CDC_ENTERED=$CDC_ROOT/Entered.cfg
    CDC_EMERGENCY=$CDC_ROOT/Emergency
    
    CDC_PROJECTS=$CDC_ROOT/Projects
    CDC_REPORTS=$CDC_ROOT/Reports
    CDC_RESULTS=$CDC_ROOT/Results
    CDC_LISTS=$CDC_ROOT/Lists
    CDC_TESTS=$CDC_ROOT/Tests
    CDC_TESTS_BIN=$CDC_ROOT/Tests_bin

    TEST_NUM=$((5 * $FACTOR))      # number of tests to gen
    LIST_NUM=$((3 * $FACTOR))      # number of lists to gen
    PROJECT_NUM=$((2 * $FACTOR))   # number of projects to gen
    RUN_NUM=$((2 * $FACTOR))       # number of runs to get
    TASK_NUM=$((2 * $FACTOR))       # number of runs to get
}


gen_subfs(){    
    echo "--- Generating SubFS ---"

    # add user
    echo "[Install] Add user $CDC_USER"
    useradd -M -s /bin/bash -U $CDC_USER
    
    # create dirs
    MASK_ACCESS="0660"
    echo "[Install] Create file structure with access mask $MASK_ACCESS"
    mkdir -m $MASK_ACCESS -p $CDC_ROOT 
    mkdir -m $MASK_ACCESS -p $CDC_PROJECTS $CDC_LISTS $CDC_TESTS $CDC_TESTS_BIN $CDC_REPORTS $CDC_RESULTS
    
    # create files
    touch $CDC_LOGIN $CDC_ENTERED $CDC_EMERGENCY
    
    # add admin to login
    echo "[Install] Add Admin user"
    echo 'Admin =
    {
        level = 0;
    }' > $CDC_LOGIN
    
    # normal mode
    echo "[Install] Set normal mode"
    echo 0 > $CDC_EMERGENCY
    
    # chown
    echo "[Install] Set $CDC_USER as owner of file structure"
    chown -R $CDC_USER:$CDC_USER $CDC_ROOT
    chmod -R ug+rwx $CDC_ROOT
}


remove_subfs(){
    echo "--- Removing SubFS ---"

    # remove user
    echo "[Remove] Remove user $CDC_USER"
    userdel $CDC_USER
    
    # remove dirs
    echo "[Remove] Remove file structure"
    rm -rf $CDC_ROOT
}


print_help(){
    echo "Usage: $0 [PARAMS]"
    echo "PARAMS"
    echo "-h|--help             : print help"
    echo "-t|--type <type>      : choose one of the allowed types:"
    echo "                      `echo ${ALLOWED_TYPES} | tr '\n' ' '`"
    echo "                      [default: $TYPE]"
    echo "-p|--path <path>      : path with CDC root [default: $CDC_ROOT]"
    echo "-f|--factor <number>  : number to gen different types, each type generate"
    echo "                        number is multiplied on factor. Default, factor = $FACTOR."
    echo "                        -> test number with factor    = $TEST_NUM"
    echo "                        -> list number with factor    = $LIST_NUM"
    echo "                        -> run number with factor     = $RUN_NUM"
    echo "                        -> project number with factor = $PROJECT_NUM"
    echo "                        -> task number with factor    = $TASK_NUM"
    echo "-r|--remove           : remove CDC root (like postrm)"
    echo "-c|--create           : create CDC root (line postinst)"
    echo "--<type>-postfix      : post of <type> file"
    echo "                        test postfix      = $TEST_POSTFIX"
    echo "                        list postfix      = $LIST_POSTFIX"
    echo "                        run postfix       = $RUN_POSTFIX"
    echo "                        project postfix   = $PROJECT_POSTFIX"
    echo "                        task postfix      = $TASK_POSTFIX"
}


remove_spaces(){
    if test -t 0 ; then                            
        printf "%s\n" "Method read from stdin" 1>&2
        return 1                                   
    fi                                             
                                                   
    sed "s/^[ \t]*//" | sed "s/[ \t]*$//" | sed "s/,$//" <& 0     
}


# $1 number of words
gen_word(){
    local number=$1
    local answer=""

    for i in `seq 1 $number`; do
        local factor=$(($RANDOM % 3 + 1))   # from 1 to 3
        local line=$(($RANDOM * $factor))   # american dict is about 100k
        answer+="`sed -n "${line}p" /usr/share/dict/words` "
    done

    echo "$answer" | remove_spaces
}


# $1 - dir
get_random_files_json(){
    local test_number=`ls --color=never $1 | wc -l`
    local answer="["

    # get half of files in dir
    for i in `seq 1 $(($RANDOM % (test_number / 2) + 1))`; do
        local line=$(($RANDOM % $test_number + 1))
        answer+="\"`ls --color=never $1 | sed -n "${line}p"`\", "
    done

    answer=`echo "$answer" | remove_spaces`
    answer+="]"

    echo "$answer"
}


gen_test(){
    for i in `seq 1 $TEST_NUM`; do
        printf "%s\r" "Generating test $i of $TEST_NUM ..."

        local name_size=$(($RANDOM % 5 + 1))    # 5 - max name size
        local descr_size=$(($RANDOM % 20 + 1))  # 20 - max descr size

        local name=`gen_word $name_size`
        local descr=`gen_word $descr_size`
        local date=`LC_ALL=C date +%Y%m%d`

        local test_file=$CDC_TESTS/${name// /_}${TEST_POSTFIX}
        touch $test_file

        echo '{' > $test_file
        echo "    \"name\" : \"$name\","         >> $test_file
        echo "    \"description\" : \"$descr\"," >> $test_file
        echo "    \"pyScript\" : \"\"," >> $test_file
        echo "    \"date_creation\" : \"$date\"" >> $test_file
        echo '}' >> $test_file
    done

    echo "Tests are generated !"
    echo "Find in $CDC_TESTS"
    echo
}


gen_list(){
    for i in `seq 1 $LIST_NUM`; do
        printf "%s\r" "Generating list $i of $LIST_NUM ..."

        local name_size=$(($RANDOM % 5 + 1))    # 5 - max name size
        local name=`gen_word $name_size`

        local list=`get_random_files_json $CDC_TESTS`

        local list_file=$CDC_LISTS/${name// /_}${LIST_POSTFIX}
        touch $list_file

        echo '{' > $list_file
        echo "    \"name\" : \"$name\","         >> $list_file
        echo "    \"tests\" : $list"             >> $list_file
        echo '}' >> $list_file
    done

    echo "Lists are generated !"
    echo "Find in $CDC_LISTS"
    echo
}


gen_run(){
    for i in `seq 1 $RUN_NUM`; do
        printf "%s\r" "Generating run $i of $RUN_NUM ..."

        local name_size=$(($RANDOM % 5 + 1))    # 5 - max name size
        local name=`gen_word $name_size`

        local list=`get_random_files_json $CDC_TESTS`
        local lists=`get_random_files_json $CDC_LISTS`

        # get project with tasks
        local proj_size=`find $CDC_PROJECTS -not -empty -type d -name "Tasks" | wc -l`
        local line=$(($RANDOM % $proj_size + 1))
        local proj=`find $CDC_PROJECTS -not -empty -type d -name "Tasks" | sed -n "${line}p"`

        # get task
        local task_size=`find ${proj} -mindepth 1 -type d| wc -l`
        local line=$(($RANDOM % $task_size + 1))
        local task=`find ${proj} -mindepth 1 -type d | sed -n "${line}p"`

        local run_file=$proj/${task##*/}/${name// /_}${RUN_POSTFIX}
        touch $run_file

        echo '{' > $run_file
        echo "    \"name\" : \"$name\","         >> $run_file
        echo "    \"tests\" : $list,"            >> $run_file
        echo "    \"lists\" : $lists"            >> $run_file
        echo '}' >> $run_file
    done

    echo "Runs are generated !"
    echo "Find in Task dirs"
    echo
}


gen_project(){
    for i in `seq 1 $PROJECT_NUM`; do
        printf "%s\r" "Generating project $i of $PROJECT_NUM ..."

        local name_size=$(($RANDOM % 3 + 1))    # 5 - max name size
        local name=`gen_word $name_size`

        local proj_dir=$CDC_PROJECTS/${name// /_}
        local proj_file="$proj_dir/${name// /_}${PROJECT_POSTFIX}"
        mkdir -p $proj_dir $proj_dir/Tasks

        echo "Name = \"$name\""         > $proj_file
        echo "Status = \"Development\"" >> $proj_file
    done

    echo "Projects are generated !"
    echo "Find in $CDC_PROJECTS"
    echo
}


gen_task(){
    for i in `seq 1 $TASK_NUM`; do
        printf "%s\r" "Generating task $i of $TASK_NUM ..."

        local proj_size=`ls --color=never $CDC_PROJECTS | wc -l`
        local line=$(($RANDOM % $proj_size + 1))
        local proj=`ls --color=never $CDC_PROJECTS | sed -n "${line}p"`

        local name_size=$(($RANDOM % 5 + 1))    # 5 - max name size
        local comm_size=$(($RANDOM % 20 + 1))   # 20 - max descr size

        local deadline=`shuf -n1 -i$(date -d '2023-02-01' '+%s')-$(date -d '2023-12-31' '+%s') \
             | xargs -I{} date -d '@{}' '+%Y%m%d'`
        local name=`gen_word $name_size`
        local comm=`gen_word $descr_size`
        local date=`LC_ALL=C date +%Y%m%d`

        mkdir -p $CDC_PROJECTS/$proj/Tasks/${name// /_}
        local task_file=$CDC_PROJECTS/$proj/Tasks/${name// /_}/${name// /_}$TASK_POSTFIX

        echo '{' > $task_file
        echo "    \"project\" : \"$proj\","         >> $task_file
        echo "    \"name\" : \"$name\","            >> $task_file
        echo "    \"comment\" : \"$comm\","         >> $task_file
        echo "    \"deadline\" : \"$deadline\","    >> $task_file
        echo "    \"date\" : \"$date\","            >> $task_file
        echo "    \"status\" : \"dev\","            >> $task_file
        echo "    \"host\" : \"127.0.0.1\""         >> $task_file
        echo '}' >> $task_file
    done

    echo "Tasks are generated !"
    echo "Find in $CDC_PROJECTS"
    echo
}


process_args(){
    while [ -n "$1" ]; do
        case "$1" in
            -h|--help)
                print_help
                exit 0
                ;;

            -t|--type)
                shift
                echo "$1" | grep -q "$ALLOWED_TYPES" \
                    || die "Wrong type arg $1"
                TYPE="$1"
                ;;

            -f|--factor)
                shift
                echo "$1" | grep -Eo '^[0-9]+$' \
                    || die "Wrong number arg $1"
                FACTOR=$1
                ;;

            -p|--path)
                shift
                realpath "$1" \
                    || die "No such path $1"
                CDC_ROOT=`realpath $1`
                ;;

            -r|--remove)
                ACTION=remove
                ;;
            
            -c|--create)
                ACTION=create
                ;;

            --test-postfix)
                TEST_POSTFIX=$1
                ;;

            --list-postfix)
                LIST_POSTFIX=$1
                ;;

            --run-postfix)
                RUN_POSTFIX=$1
                ;;

            --project-postfix)
                PROJECT_POSTFIX=$1
                ;;

            --task-postfix)
                TASK_POSTFIX=$1
                ;;
        esac

        shift
    done

    echo "--- Input params ---"
    echo "Gen type:         $TYPE"
    echo "Gen path:         $CDC_ROOT"
    echo "Act with SubFS:   $ACTION"
    echo "Mul factor:       $FACTOR"
    echo "Test postfix:     $TEST_POSTFIX"
    echo "List postfix:     $LIST_POSTFIX"
    echo "Run postfix:      $RUN_POSTFIX"
    echo "Project postfix:  $PROJECT_POSTFIX"
    echo "Task postfix:     $TASK_POSTFIX"
    echo
}


check_root(){
    test `whoami` != 'root' && die "You must be root"
}


main(){
    check_root
    process_args $@
    update_vars

    # what to do with subfs
    case "$ACTION" in
        "create")
            gen_subfs
            ;;
        "remove")
            remove_subfs
            exit 0
            ;;
        *)
            :;;
    esac

    # gen types
    case "$TYPE" in
        "test")
            gen_test
            ;;
        "list")
            gen_list
            ;;
        "project")
            gen_project
            ;;
        "run")
            gen_run
            ;;
        "task")
            gen_project
            gen_task
            ;;
        "all")
            gen_test
            gen_list
            gen_project
            gen_task
            gen_run
            ;;
    esac
        
    return 0
}

main $@
