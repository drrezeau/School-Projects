var myUserName;
var peerUserName;
var peer;
var enemyCommand = ['0', '0', '0', '0', '0'];

function connect2Server() {
    myUserName = $("#myUsername").val();


    peer = new Peer(myUserName, {key: 'mm63227qa567ds4i', debug: 3});
    peer.on('open', function (id) {
        console.log('My peer ID is: ' + id);
    });

    peer.on('connection', receiveData);

    $("#getMyUsername").addClass('hide');
    $("#getPeerUsername").removeClass('hide');

}

function hideStuff() {
    $("#getPeerUsername").addClass('hide');
    $("#playerControls").removeClass('hide');
    gameSettings();
}

var conn;
function connect2Peer() {
    peerUserName = $("#peerUsername").val();

    conn = peer.connect(peerUserName, {
        label: 'game',
        metadata: {message: 'hi I want to play with you!'}
    });

    console.log(peer);
    conn.on('open', function(){
        receiveData(conn);
    });
    
    conn.on('error', function(err) { alert(err); });
    hideStuff();
}
function sendData(data) {
    // console.log("SEND DATA");
    conn.send(data);
}

function receiveData(conn) {
    // console.log("RECEIVE DATA");
    conn.on('data', function(data){
        //console.log(data);

        for (var i in data){
            enemyCommand[i] = data[i];
        }
    });
}