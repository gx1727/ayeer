/**
 * Created by gx1727 on 2016/10/12 0012.
 */
var win = require('./win32');
var iconv = require('iconv-lite');
var fs = require('fs'); // 载入fs模块

var win_op = ['test',
    '0djj', 'alanbeibei',
    'crt', 'php', 'notepad', 'ftp', 'firefox',
    'vhost', 'hosts'
];

function run(cmd, param) {
    if (cmd) {
        if (win_op.indexOf(cmd) >= 0) {
            eval('op_' + cmd + '(\'' + param + '\');');
        } else {
            op_default(cmd, param);
        }
    } else {
        op_ok();
    }
    // var win_ret = ayeer_api.do(cmd, param);
    // console.log(win_ret);
}

/**
 * 测试
 * @param param
 */
function op_test(param) {
    console.log(win.find_window("Notepad", 1));
    console.log(win.find_window("20161013.txt - 记事本", 2));
}
function op_ok() {
    var path = "D:\\work\\captain\\ayeer_script\\工作日志";
    var c_date = new Date();
    var year = c_date.getFullYear();
    var month = c_date.getMonth() + 1;
    var date = c_date.getDate();
    var file_name = "";

    file_name += year;
    if (month < 10) {
        file_name += '0';
    }
    file_name += month;

    if (date < 10) {
        file_name += '0';
    }
    file_name += date;

    path += '\\' + file_name;

    if (!fs.existsSync(path)) { //目录不存在
        fs.mkdirSync(path, 0777);
    }
    path += '\\';
    path += file_name + '.txt';
    if (!fs.existsSync(path)) {
        var fd = fs.openSync(path, 'w');
        fs.close(fd);
    }

    var hwnd = win.find_window(file_name + ".txt - 记事本", 2);
    if (hwnd > 0) {
        win.select_window(hwnd);
    } else {
        win.shell_execute(path);
    }
}

function op_0djj(param) {
    win.shell_execute("D:\\work\\captain\\0djj");
    win.shell_execute("D:\\work\\captain\\ayeer\\零点九九");
}

function op_alanbeibei(param) {
    win.shell_execute("D:\\work\\captain\\alanbeibei");
    win.shell_execute("D:\\work\\captain\\ayeer\\阿蓝贝贝");
}

/**
 * crt
 * @param param
 */
function op_crt(param) {
    win.shell_execute("D:\\work\\tools\\SecureCRT\\SecureCRT.exe");
}

/**
 * phpstorm
 * @param param
 */
function op_php(param) {
    win.shell_execute("C:\\Program Files\\JetBrains\\PhpStorm 2017.1.3\\bin\\phpstorm64.exe");
}


/**
 * ftp
 * @param param
 */
function op_ftp(param) {
    win.shell_execute("F:\\Program Files\\FileZilla FTP Client\\filezilla.exe");
}
function op_firefox(param) {
    win.shell_execute("F:\\Program Files (x86)\\Mozilla Firefox\\firefox.exe");
}


function op_vhost(param) {
    win.shell_execute("D:\\work\\xampp\\apache\\conf\\extra\\httpd-vhosts.conf");
    win.shell_execute("D:\\work\\phpStudy\\nginx\\conf\\vhosts2.conf");
}

function op_hosts(param) {
    win.shell_execute("C:\\Windows\\System32\\drivers\\etc\\hosts");
}


function op_default(cmd, param) {
    console.log("cmd:" + cmd + " param:" + param);
}

exports.run = run;
