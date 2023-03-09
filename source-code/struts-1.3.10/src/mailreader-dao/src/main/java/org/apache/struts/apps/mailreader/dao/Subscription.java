/*
 * $Id: Subscription.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


package org.apache.struts.apps.mailreader.dao;


/**
 * <p>A <strong>Subscription</strong> which is stored, along with the
 * associated {@link User}, in a {@link UserDatabase}.</p>
 *
 * @version $Rev: 471754 $ $Date: 2006-11-06 08:55:09 -0600 (Mon, 06 Nov 2006) $
 */

public interface Subscription {


    // ------------------------------------------------------------- Properties


    /**
     * Return the auto-connect flag.
     */
    public boolean getAutoConnect();


    /**
     * Set the auto-connect flag.
     *
     * @param autoConnect The new auto-connect flag
     */
    public void setAutoConnect(boolean autoConnect);


    /**
     * Return the host name.
     */
    public String getHost();


    /**
     * Return the password.
     */
    public String getPassword();


    /**
     * Set the password.
     *
     * @param password The new password
     */
    public void setPassword(String password);


    /**
     * Return the subscription type.
     */
    public String getType();


    /**
     * Set the subscription type.
     *
     * @param type The new subscription type
     */
    public void setType(String type);


    /**
     * Return the {@link User} owning this Subscription.
     */
    public User getUser();


    /**
     * Return the username.
     */
    public String getUsername();


    /**
     * Set the username.
     *
     * @param username The new username
     */
    public void setUsername(String username);


}
