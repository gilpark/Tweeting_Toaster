<?php
session_start();
require 'autoload.php';
use Abraham\TwitterOAuth\TwitterOAuth;

define('CONSUMER_KEY', '######'); // add your app consumer key between single quotes
define('CONSUMER_SECRET', '#####'); // add your app consumer secret key between single quotes
define('OAUTH_CALLBACK', 'http://your.domain.com/callback.php'); // your app callback URL

$a_token = '######';
$a_token_secret = '######';
$msg = $_GET['msg'];


	$connection = new TwitterOAuth(CONSUMER_KEY, CONSUMER_SECRET, $a_token,$a_token_secret);
	
	// getting basic user info
	$user = $connection->get("account/verify_credentials");
	
	// printing username on screen
	echo $user->screen_name;

	// posting tweet on user profile
	$post = $connection->post('statuses/update', array('status' => $msg ));

	// displaying response of $post object
	print_r($post);

